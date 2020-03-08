#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll n, m, k, ans = 1;

int main() {

    cin >> n >> m >> k;
    if(k == 1 || k > n) {
        for (int i = 1;i <= n;i++)
            ans = (ans * m) % mod;

        return cout << ans, 0;
    }
    if(n == k) {
        n = (n + 1) / 2;
        for (int i = 1; i <= n;i++)
            ans = (ans * m) % mod;

        return cout << ans, 0;
    }

    if(k % 2 != 0)
        return cout << (m * m) % mod,0;

    return cout << m, 0;
}
