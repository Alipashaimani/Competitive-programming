#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, k; cin >> n >> k;
    return cout << (n/k & 1 ? "YES" : "NO") << '\n', 0;
}