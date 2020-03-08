#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
int n, m;
int color[MAXN], adj[MAXN][MAXN];
bool mark[MAXN];
bool flag = false;

void dfs(int v, int cnt){
    if (flag or mark[v])
        return;

    color[v] = cnt;
    mark[v] = true;

    for (int i = 0; i < n; i++)
        if (adj[v][i] != -1){
            if (i != v && color[i] != -1 && (color[v] ^ (adj[v][i] ^ 1)) != color[i])
                flag = true;
            dfs(i, cnt ^ (adj[v][i] ^ 1));
        }
}

int main(){
    memset(adj, -1, sizeof adj);
    memset(color, -1, sizeof color);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, z;    cin >> x >> y >> z;
        x--, y--;
        adj[x][y] = adj[y][x] = z;
    }

    for (int i = 0; i < n; i++)
        if (color[i] == -1)
            dfs(i, 0);

    if (flag)
        return cout << "Impossible" << endl , 0;

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (!color[i])
            ans.push_back(i + 1);

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";

}