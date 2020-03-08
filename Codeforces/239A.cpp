#include <bits/stdc++.h>
using namespace std;

int y, k, n, m;

int main() {
    cin >> y >> k >> n;
    m = k - y % k;
    if (m == 0)
        m = k;
    if (m + y > n) {
        cout << -1;
        return 0;
    }
    for ( int i = m ; i+y <= n ; i+=k){
        cout << i << " ";
    }
    return 0;
}
