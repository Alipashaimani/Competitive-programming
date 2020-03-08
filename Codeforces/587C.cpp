#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100, lg = 18;
int n, m, q, dis[MAXN], par[MAXN][20];
vector <int> adj[MAXN], in[MAXN][20], vec;

vector <int> meg(vector <int> a, vector <int> b) {
    vector <int> c;
    c.resize(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    if (c.size() > 10)
        c.resize(10);
    return c;
}

int lca(int u, int v) {
    if (dis[u] < dis[v])
        swap(u, v);

    for (int i = lg; i > -1; i--)
        if (dis[u] - (1 << i) >= dis[v]){
            vec = meg(in[u][i], vec);
            u = par[u][i];
        }

    if (u == v) {
        vec = meg(in[u][0], vec);
        return u;
    }

    for (int i = lg; i > -1; i--)
        if (par[u][i] != par[v][i]) {
            vec = meg(in[u][i], vec);
            vec = meg(in[v][i], vec);
            u = par[u][i];
            v = par[v][i];
        }

    vec = meg(in[u][1], vec);
    vec = meg(in[v][0], vec);

    return par[u][0];
}

void dfs(int v) {
    for (int i = 1; i <= lg; i++) {
        par[v][i] = par[par[v][i - 1]][i - 1];
        in[v][i] = meg(in[v][i - 1], in[v][i]);
        in[v][i] = meg(in[par[v][i - 1]][i - 1], in[v][i]);
    }
    for (auto u : adj[v])
        if (dis[u] == 0 && u != 1){
            par[u][0] = v;
            dis[u] = dis[v] + 1;
            dfs(u);
        }
}

int main() {

    cin >> n >> m >> q;
    for (int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int x, i = 0; i < m; i++) {
        cin >> x;
        in[x][0].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++)
        if (in[i][0].size() > 10)
            in[i][0].resize(10);

    dfs(1);
    while (q--) {
        int x, y, a;    cin >> x >> y >> a;
        lca(x, y);
        int t = min(a, (int)vec.size());
        int h = 0 ;
        cout << t << " ";
        while (h < t)
            cout << vec[h++] << " ";

        cout << endl;
        vec.clear();
    }
    return 0;
}
