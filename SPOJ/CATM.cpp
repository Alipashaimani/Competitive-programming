#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >>k;
    for (long long i = 0; i < k; ++i) {
        long long a1, a2, b1, b2, c1, c2;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        if (a1 == b1 || a1 == c1 || a2 == b2 || a2 == c2) {
            cout << "YES" << '\n';
        }
        else if ((a1 < b1 && a1 < c1) || (a1 > c1 && a1 > b1) || (a2 < b2 && a2 < c2) || (a2 > c2 && a2 > b2)) {
            cout << "YES" << '\n';
        }
        else if (abs(b1 - a1) == abs(b2 - a2) && abs(c1 - a1) == abs(c2 - a2)) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}
