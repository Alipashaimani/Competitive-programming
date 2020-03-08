#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;


vector<pair<int, int>> q;
map<pair<int, int>, vector<pair<int, int>>> adj;
map<pair<int, int>, bool> mark;

void dfs (pair<int, int> v) {
    mark[v] = true;
    for (auto u: adj[v])
        if (!mark[u])
            dfs(u);
}

int main () {
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int type, x, y; cin >> type >> x >> y;
        if (type == 1) {
            for (auto j: q) {
                if ((j.first < x && x < j.second) || (j.first < y && y < j.second))
                   adj[{x, y}].push_back(j);
                if ((x < j.first && j.first < y) || (x < j.second && j.second < y))
                    adj[j].push_back({x, y});
            }
            q.push_back({x, y});
        } else {
            mark.clear();
            dfs(q[x - 1]);
            cout << (mark[q[y - 1]] ? "YES\n" : "NO\n");
        }
    }
}


