#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
bitset<1000>rmark,cmark;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;   cin >> x >> y;  x--,y--;
        rmark[x] = 1;
        cmark[y] = 1;
    }
    for (int i = 1; i < n-1; i++) {
        if (!rmark[i])
            ans++;
        if (!cmark[i])
            ans++;
    }
    if (n&1 && !rmark[n/2] && !cmark[n/2])
        ans--;
    cout << ans << endl;
}