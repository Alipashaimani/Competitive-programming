#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 510*3 + 10;

char arr[MAXN][MAXN];
char c[MAXN][MAXN];

int maxi, maxj;
int a = MAXN, b = MAXN;

int main() {

    int n, m; cin >> n >> m;
    for (int i = 0 ; i < n; ++i)
        for (int j = 0 ; j < m ; ++j) {
            cin >> c[i][j];
            if (c[i][j] == 'X') {
                a = min(a, i);
                b = min(b, j);
                maxi = max(maxi, i);
                maxj = max(maxj, j);
            }
        }
    for (int i = a ; i <= maxi ; ++i)
        for (int j = b ; j <= maxj ; ++j)
            if (c[i][j] == '.')
                return cout << "NO\n", 0;
    cout << "YES\n";

}