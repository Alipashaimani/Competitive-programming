#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int mod = 1e9 + 7;

long long p2[MAXN], ans;
string s;

int main() {
    cin >> s;
    p2[0] = 1;
    for (int i = 1; i <= 400; i++)
        p2[i] = p2[i - 1] * 2 % mod;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            ans = (ans + p2[2 * s.size() - i - 2]) % mod;

    return cout << ans << '\n', 0;
}
