#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
int a[MAXN], st[MAXN], ft[MAXN], h[MAXN], t;
vector <int> adj[MAXN];
int seg[4 * MAXN];
bool mark[MAXN];

void dfs(int v, int q){
    mark[v] = true;
    st[v] = t++;
    h[v] = q;
    for(int u:adj[v])
        if (!mark[u])
            dfs(u, q + 1);
    ft[v] = t;
}

void upd(int l, int r, int val, int id, int b, int e){
    if (l >= e || b >= r)
        return;
    if (l <= b && e <= r){
        seg[id] += val;
        return;
    }
    int mid = (b + e) >> 1;
    upd(l, r, val, id  << 1, b, mid);
    upd(l, r, val, id  << 1 | 1, mid, e);
}

int query(int x, int id, int b, int e){
    if (e - b == 1)
        return seg[id];
    int mid = (b + e) >> 1;
    if (x < mid)
        return seg[id] + query(x, id << 1, b, mid);
    else
        return seg[id] + query(x, id << 1 | 1, mid, e);
}

int main(){
    int n, q;    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0 ; i < n - 1; i++){
        int x,y;    cin >> x >> y;  x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0,0);

    for(int i = 0; i < q; i++){
        int t;  cin >> t;
        if (t - 1){
            int x;  cin >> x;   x--;
            int ans = query(st[x], 1, 0, n);
            if (h[x] % 2)
                ans *= -1;
            cout << a[x] + ans << endl;
        }else{
            int x, val; cin >> x >> val;    x--;
            if (h[x] % 2)
                val *= -1;
            upd(st[x], ft[x], val,1,0,n);
        }
    }
    return 0;
}