#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

vector<int> adj[MAXN], *vec[MAXN];
int col[MAXN], pw[MAXN], goni[MAXN], sz[MAXN];
long long sum[MAXN];

void getsz(int v = 1, int pre = -1){
    sz[v] = 1;
    for(auto u : adj[v]) {
        if (u != pre) {
            getsz(u, v);
            sz[v] += sz[u];
        }
    }
}

void dfs(int v, int pre, bool type) {

    int idx = -1;
    int bigchild = -1;

    for(auto i : adj[v])
        if(sz[i] > idx && i != pre)
            idx = sz[i], bigchild = i;

    for(auto i : adj[v])
        if(i != bigchild && i != pre)
            dfs(i, v, 0);

    if(bigchild != -1) {
        dfs(bigchild, v, 1);
        vec[v] = vec[bigchild];
        sum[v] = sum[bigchild];
        pw[v] = pw[bigchild];
    }
    else
        vec[v] = new vector<int> ();

    vec[v] -> push_back(v);

    goni[col[v]]++;

    if (goni[col[v]] == pw[v])
        sum[v] += col[v];

    else if (goni[col[v]] > pw[v]) {
        sum[v] = col[v];
        pw[v] = goni[col[v]];
    }

    for (auto i : adj[v])
        if (i != bigchild && i != pre)
            for (auto j : *vec[i]) {
                goni[col[j]]++;

                vec[v] -> push_back(j);

                if (goni[col[j]] == pw[v])
                    sum[v] += col[j];

                else if (goni[col[j]] > pw[v]) {
                    sum[v] = col[j];
                    pw[v] = goni[col[j]];

                }
            }

    if(!type)
        for(auto u : *vec[v])
            goni[col[u]]--;
}


int main () {
    int n;  cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> col[i];

    for (int i = 0; i < n - 1; ++i) {
        int x, y;   cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    getsz();
    dfs(1, -1, 0);

    for (int i = 1; i <= n; ++i)
        cout << sum[i] << ' ';
}