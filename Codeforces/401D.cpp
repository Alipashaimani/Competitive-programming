#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e2 + 10, MAXM = 20;
long long dp[1<<18][MAXN], m, x, p[MAXM], cnt[MAXM], f[MAXM];
string n;

int main(){
    p[0]= f[0] = dp[0][0] = 1;
    for (int i = 1; i < 18; i++){
        p[i] = p[i - 1] * 10;
        f[i] = f[i - 1] * i;
    }
    cin >> n >> m;
    for (int i = 1; i <= n.size(); i++){
        x = n[i - 1] - '0';
        cnt[x]++;
        for (int mask = 0; mask < (1 << n.size()); mask++)
            if(__builtin_popcount(mask)==i-1)
                for (int j = 0; j < n.size()-(x==0); j++)
                    if(!(mask>>j & 1))
                        for (int k = 0; k <= m; k++)
                            dp[mask+(1<<j)][(k + (x*p[j])) % m] += dp[mask][k];


    }

    for (int i = 0; i < 10; ++i)
        dp[(1<<n.size())-1][0] /= f[cnt[i]];

    return cout << dp[(1 << n.size()) - 1][0] << "\n", 0;
}
