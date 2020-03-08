#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  cin >> n;
    if (n == 1)
        return cout << 1 << ' ' << 1 << '\n' << 1 << '\n', 0;
    return cout << 2 * (n - 1) << ' ' << 2 << '\n' << 1 << ' ' << 2 << '\n' , 0;
}