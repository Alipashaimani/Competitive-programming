#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

string s;
ll k, sz, ans = 0;

ll pw(ll a, ll b) {
    return b? 1ll * pw(1ll * a * a % MOD, b / 2) * (b & 1? a: 1) % MOD: 1;
}

ll ca(ll ind){
    ll a = (pw(2, k * sz) + MOD - 1) % MOD;
    ll b = (pw(2, sz) + MOD - 1) % MOD;
    ll c = pw(2, ind);

    a = (a * pw(b, MOD - 2)) % MOD;
    return  (c * a) % MOD;
}

int main(){
    cin >> s >> k;
    sz = s.size();

    for (int i = 0; i < sz; i++){
        if (s[i] == '5' || s[i] == '0'){

        if (k == 1)
            ans = (ans + pw(2, i)) % MOD;

        else
            ans = (ans + ca(i)) % MOD;
        }
    }
    return cout << ans << '\n', 0;
}