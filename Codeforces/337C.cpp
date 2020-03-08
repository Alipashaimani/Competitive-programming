#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 9;

ll n,m,k;

ll powerF(ll a, ll b) {return b? 1ll * powerF(1ll * a * a % MOD, b / 2) * (b & 1? a: 1) % MOD: 1;}

int main(){
    cin >> n >> m >> k;
    if((k - 1) * (n - m) >= m)
        return cout << m << '\n' ,0;

    ll res = (k - 1) * (n - m);
    n -= k * (n - m);
    res += (powerF(2, n / k) + MOD - 1) * 2 % MOD * k % MOD + (n%k);
    res %= MOD;

    return cout << res << '\n', 0;
}