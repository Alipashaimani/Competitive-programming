#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;

vector<int> adj[MAXN];
char a[MAXN];
int sz[MAXN], h[MAXN];
int n, m;
vector<pair<int, int>> q[MAXN];
bool ans[MAXN];

int goni[MAXN][50];
vector<int> *vec[MAXN];

bool check (int x) {
    int cnt = 0;
    for (int i = 0; i < 50; i++)
        cnt += (goni[x][i] % 2 == 1);
    return cnt >= 2;
}

void get_sz (int v, int pre) {
    for (int u: adj[v])
        if (pre != u) {
            h[u] = h[v] + 1;
            get_sz(u, v);
            sz[v] += sz[u];
        }
    sz[v]++;
}

void dfs (int v, int pre, int type) {
    int idx = -1;
    int bigchild = -1;
    for (int i: adj[v])
        if (i != pre && idx <= sz[i]) {
            bigchild = i;
            idx = sz[i];
        }

    for (int i: adj[v])
        if (pre != i && i != bigchild)
            dfs(i, v, 0);

    if (bigchild != -1){
        dfs(bigchild, v, 1);
        vec[v] = vec[bigchild];
    }
    else
        vec[v] = new vector<int> ();

    vec[v] -> push_back(v);
    goni[h[v]][a[v] - 'a']++;

    for (int i: adj[v])
        if (i != pre && i != bigchild)
            for (int u: *vec[i]) {
                goni[h[u]][a[u] - 'a']++;
                vec[v] -> push_back(u);
            }

    for (auto y: q[v])
        ans[y.second] = check(y.first);

    if (!type)
        for (int i: *vec[v])
            goni[h[i]][a[i] - 'a']--;

}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++) {
        int v, h; cin >> v >> h;
        q[v].push_back({h , i});
    }

    h[1] = 1;
    get_sz(1, -1);
    dfs(1, -1, 1);

    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "No\n" : "Yes\n");
}
