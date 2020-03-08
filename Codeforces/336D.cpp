#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

ll fact[MAXN + 10], ans;

ll power(ll a, ll b){
    if (b == 1)
        return a % MOD;
    ll ans = power(a, b/2);
    ans = (ans * ans) % MOD;
    if (b & 1)
        ans = ans * a % MOD;
    return ans;
}

ll C(ll n, ll k){
    if (k > n || k < 0)
        return 0;
    return fact[n] * (power(fact[k] * fact[n-k] % MOD, MOD - 2)) % MOD;
}

int main(){
    int n, m, g; cin >> n >> m >> g;

    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    if (n == 0 && g == 1){
            if (m == 1)
                return cout << "1\n" ,0;
            return cout << "0\n", 0;
        }
    if (g == 1)
        n--;

    for (int i = 0; i< n + m; i += 2){
        if (i < n + m-1 && m>=1 && n>=i)
            ans = (ans + C(n + m-i-1, m-1)) % MOD;
        if (n >= i + 1){
        if (i == n + m-2 && m >= 1)
            ans++;
        if (i == n + m-1)
            ans++;
        }
    }

    return cout << ans << '\n' , 0;

}