#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 100;
vector <int> adj[MAXN];
bool mark[MAXN];
int n, m;
int ans;
int cnt = 0;

void dfs(int v) {
    mark[v] = true;
    for (auto i : adj[v])
        if (!mark[i])
            dfs(i);
}


int main () {
    cin >> n >> m;
    for(int i = 0; i < n; i++){

        int x, y;   cin >> x;

        if (!x)
            cnt++;

        for(int j = 0; j < x; j++){
            cin >> y;   y--;
            adj[i].push_back(y + m);
            adj[y + m].push_back(i);
        }
    }

    if (cnt == n)
        return cout << n << '\n' , 0;

    dfs(0);
    for (int i = 1; i < n; ++i)
        if (!mark[i]) {
            ans++;
            dfs(i);
        }

    cout << ans << '\n';

}
