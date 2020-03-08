#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

map<int, vector<int> > mp;
vector<int> adj[MAXN];
int fn[MAXN], st[MAXN], ans[MAXN], lazy[4 * MAXN], n, q, t = -1;
pair<int, int> seg[MAXN * 4];

void dfs(int v, int pre) {
    st[v] = ++t;
    for (int i : adj[v])
        if (i != pre)
            dfs(i, v);
    fn[v] = t;
}

void built(int b, int e, int id){
    if (e - b == 1){
        seg[id] = {0, 1};
        return;
    }
    int mid = (b + e) >> 1;
    built(b, mid, id << 1);
    built(mid, e, id << 1 | 1);
    seg[id] = {0, e - b};
    return;
}

pair<int, int > upd(int id){
    int xx = seg[id << 1].first + lazy[id << 1];
    int xy = seg[id << 1].second;
    int yx = seg[id << 1 | 1].first + lazy[id << 1 | 1];
    int yy = seg[id << 1 | 1].second;

    if (xx == yx)
        return {xx, xy + yy};

    return min(pair<int, int>(xx, xy), pair<int, int>(yx, yy));
}

void query(int l, int r, int x, int b, int e, int id){
    if (b >= r || e <= l)
        return;
    if (b >= l && e <= r){
        lazy[id] += x;
        return;
    }
    int mid = (b + e) >> 1;
    query(l, r, x, b, mid, id << 1);
    query(l, r, x, mid, e, id << 1 | 1);

    seg[id] = upd(id);

    return;
}

void sol(int v, int pre) {

    for (int j : mp[v]) {
        query(st[j], fn[j] + 1, 1, 0, n, 1);
        query(st[v], fn[v] + 1, 1, 0, n, 1);
    }

    ans[v] = n - (seg[1].first + lazy[1] ? 0 : seg[1].second) - 1;

    for (int i : adj[v]) {
        if (i == pre)
            continue;
        sol(i, v);
    }

    for (int j : mp[v]) {
        query(st[j], fn[j] + 1, -1, 0, n, 1);
        query(st[v], fn[v] + 1, -1, 0, n, 1);
    }
}


int main() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(q--){
        int x, y; cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    built(0, n, 1);
    dfs(1, 0);
    sol(1, 0);

    for (int i = 1; i <= n; ++i)
        cout << (ans[i] > 0 ? ans[i] : 0) << " ";

    return 0;
}
