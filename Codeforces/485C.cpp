#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;  cin >> t;
    while (t--) {
        long long l, r;     cin >> l >> r;
        long long p = 1;
        while ((p | l) <= r) {
            l |= p;
            p <<= 1;
        }
        cout << l << '\n';
    }
}
