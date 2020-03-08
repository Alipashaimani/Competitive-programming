#include <bits/stdc++.h>
using namespace std;

#define int long long

const int Mod = 1e9 + 7;
const int MAXN = 3e5 + 100;

vector <int> adj[MAXN];
int n, h[MAXN], st[MAXN], ft[MAXN], s[MAXN], f[MAXN];

int t = -1;

void dfs(int v) {
    st[v] = ++t;
    for (auto x : adj[v]) {
        h[x] = h[v] + 1;
        dfs(x);
    }
    ft[v] = t;
}

void add(int *arr, int p1, int p2, int x) {
    int x2 = -x;
    x = (x + Mod) % Mod;
    for (p1++; p1 < MAXN; p1 += p1 & -p1)
        arr[p1] = (arr[p1] + x) % Mod;

    x2 = (x2 + Mod) % Mod;
    for (p2++; p2 < MAXN; p2 += p2 & -p2)
        arr[p2] = (arr[p2] + x2) % Mod;

}

int get(int *arr, int i) {
    int ans = 0;
    for (i++; i > 0; i -= i & -i)
        ans = (ans + arr[i]) % Mod;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v;  cin >> v;   v--;
        adj[v].push_back(i);
    }
    dfs(0);
    int q;  cin >> q;
    while (q--) {
        int type;   cin >> type;
        if (type == 1) {
            int v, x, k;    cin >> v >> x >> k; --v;
            x = (x + 1 * h[v] * k % Mod) % Mod;
            add(s, st[v], ft[v] + 1, x);
            add(f, st[v], ft[v] + 1, k);
        }
        if (type == 2) {
            int v;  cin >> v;   --v;
            cout << (get(s, st[v]) - 1 * h[v] * get(f, st[v]) % Mod + Mod) % Mod << endl;
        }
    }
}