#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 100;
const int MOD = 1e9 + 7;
int dp[MAXN][MAXN];
set<int> fnd, fix, t1, t2;
long long n, k;

int main(){
    int m;  cin >> m;
    for(int i = 1; i <= m; ++i)
        fix.insert(i);

    for(int i = 1; i <= m; ++i){
        int x;    cin >> x;
        if(x==-1)
            fnd.insert(i);
        else
            fix.erase(x);
    }
    for(auto i : fix)
        if(fnd.count(i))
            t2.insert(i);
        else
            t1.insert(i);

    n = t1.size();
    k = t2.size();

    dp[0][0] = 1;

    for(int i = 0; i <= n + k; ++i){
        for(int j = 0; j <= k; ++j){

            if(j==0&&i>=1)
                dp[i][j] = (1LL * i * dp[i-1][j]) % MOD;

            if(i>=1&&j>=1)
                dp[i][j] = ((long long)dp[i][j] +  1LL * (i-1) * dp[i-1][j-1]) % MOD;

            if(i>=2&&j>=2)
                dp[i][j] = ((long long)dp[i][j] + 1LL * (j-1) * dp[i-2][j-2]) % MOD;
        }
    }
    cout<<dp[n + k][k] << endl;
}