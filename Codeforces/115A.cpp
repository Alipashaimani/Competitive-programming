#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4;
int table[MAXN];
int n, mx;

void dfs(int v, int h) {
    mx = max(mx, h);
    if (table[v] != -1)
        dfs(table[v], h + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> table[i];

    for (int i = 1; i <= n; i++)
        dfs(i, 0);
    cout << ++mx << '\n';
    return 0;
}