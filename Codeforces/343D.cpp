#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;
const int INF = 1e8;

vector<int> adj[MAXN];
int t = 0, st[MAXN], ft[MAXN], seg[MAXN * 4], mx[MAXN * 4];

void dfs(int v, int p){
    st[v] = t ++;
    for(int i = 0; i < adj[v].size(); i++)
        if(adj[v][i] != p)
            dfs(adj[v][i], v);
    ft[v] = t;
}

void empty(int l, int r, int x, int val, int id){
    if(r - l == 1){
        mx[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if(x < mid)
        empty(l, mid, x, val, id << 1);
    else
        empty(mid, r, x, val, id << 1 | 1);
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}

int querymax(int l, int r, int b, int e, int id){
    if(e <= l or r <= b)
        return -INF;
    if(b <= l and r <= e)
        return mx[id];
    int mid = (l + r) >> 1;
    return max(querymax(l, mid, b, e, id << 1), querymax(mid, r, b, e, id << 1 | 1));
}

void fill(int l, int r, int b, int e, int val, int id){
    if(e <= l or r <= b)
        return ;
    if(b <= l and r <= e){
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if(seg[id] != 0){
        seg[id << 1] = seg[id << 1 | 1] = seg[id];
    }

    fill(l, mid, b, e, val, id << 1);
    fill(mid, r, b, e, val, id << 1 | 1);
    seg[id] = 0;
}

int query(int l, int r, int x, int id){
    if(seg[id] != 0)
        return seg[id];
    int mid = (l + r) >> 1;
    if(x < mid)
        return query(l, mid, x, id << 1);
    else
        return query(mid, r, x, id << 1 | 1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;  cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;   cin >> u >> v;
        u --; v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < 4 * MAXN; i++)
        seg[i] = -1;

    dfs(0, -1);
    int q;  cin >> q;
    for(int i = 1; i <= q; i++) {
        int type, v;   cin >> type >> v;    v--;
        if(type == 1)
            fill(0, n, st[v], ft[v], i, 1);
        if(type == 2)
            empty(0, n, st[v], i, 1);
        if(type == 3)
            cout << (querymax(0, n, st[v], ft[v], 1) <= query(0, n, st[v], 1)) << endl;
    }
    return 0;
}