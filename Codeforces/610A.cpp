#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n; cin >> n;
    cout << (n & 1 ? 0 : ( (!n % 4) ? n/4 - 1 : (n/2 - 1)/2));
}