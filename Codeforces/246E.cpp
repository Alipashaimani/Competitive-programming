#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

vector<int> adj[MAXN];
int sz[MAXN], h[MAXN];
string name[MAXN];
vector<pair<int, int>> query[MAXN];
int ans[MAXN];
map<string, int> goni[MAXN];
vector<int> *vec[MAXN];

void getsz (int v, int pre) {
    for (int i: adj[v])
        if (i != pre) {
            h[i] = h[v] + 1;
            getsz(i, v);
            sz[v] += sz[i];
        }
    ++sz[v];
}

void dfs (int v, int pre, bool type) {
    int idx = -1;
    int bigchild = -1;

    for (int u: adj[v])
        if (u != pre && sz[u] > idx)
            idx = sz[u], bigchild = u;

    for (int u: adj[v])
        if (u != pre && u != bigchild)
            dfs(u, v, 0);

    if (bigchild != -1) {
        dfs(bigchild, v, 1);
        vec[v] = vec[bigchild];
    }
    else
        vec[v] = new vector<int> ();

    vec[v] -> push_back(v);
    ++goni[h[v]][name[v]];

    for (int u: adj[v])
        if (u != pre && u != bigchild)
            for (int i: *vec[u]){
                vec[v] -> push_back(i);
                goni[h[i]][name[i]]++;
            }

    for (auto i: query[v])
        ans[i.second] = goni[i.first].size();

    if (!type)
        for (int i: *vec[v]){
            goni[h[i]][name[i]]--;
            if (goni[h[i]][name[i]] == 0)
                goni[h[i]].erase(name[i]);
        }
}

int main () {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> name[i] >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    getsz(0, -1);

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, k; cin >> v >> k;
        query[v].push_back({h[v] + k, i});
    }

    dfs(0, -1, 1);

    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
