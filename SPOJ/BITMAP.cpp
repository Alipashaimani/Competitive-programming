#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 40 + 10;
int d[MAXN], arr[MAXN], n, m;
vector <int> v[MAXN];
queue <int> q;
void bfs(int n) {
    if (q.empty()) {
        return;
    }
    for (int i = 0; i < v[n].size(); ++i) {
        if (!d[v[n][i]]) {
            q.push(v[n][i]);
            d[v[n][i]] = (d[n] + 1);
        }
    }
    q.pop();
    bfs(q.front());
}
int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k) {
        for (int i = 0; i <= n * m; ++i) {
            arr[i] = 0;
            v[i].clear();
            d[i] = 0;
        }
        cin >> n >> m;
        for (int i = 0; i < n * m; ++i) {
            char x;
            cin >> x;
            arr[i] = x - '0';
            if (arr[i]) {
                v[n * m].push_back(i);
            }
            if (i % m != m - 1) {
                v[i].push_back(i + 1);
                v[i + 1]. push_back(i);
            }
        }
        for (int i = 0; i < n * m; ++i) {
            if (i + m < n * m) {
                v[i].push_back(i + m);
                v[i + m].push_back(i);
            }
        }
        q.push(n * m);
        d[n * m] = 1;
        bfs(n * m);
        for (int i = 0; i < n * m; ++i) {
            cout << d[i] - 2 << ' ';
            if (i % m == m - 1) {
                cout << '\n';
            }
        }
    }
    return 0;
}
