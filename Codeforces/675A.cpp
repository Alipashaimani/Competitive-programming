#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0)
        return cout << (a == b?"YES\n":"NO\n"), 0;

    return cout << ((b - a) % c == 0 && (b - a) / c >= 0?"YES\n":"NO\n"),0;
}