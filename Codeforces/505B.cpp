#include<bits/stdc++.h>
using namespace std;

const int maxN = 100 + 10;
int n, m;
vector<int>	adj[maxN][maxN];
bool mark[maxN];

bool dfs(int v, int u, int c){
    if (v == u)
        return	true;

    if (mark[v])
        return	false;

    mark[v] = true;

    for (int i = 0 ; i < adj[v][c].size() ; ++i)
        if (dfs(adj[v][c][i], u, c))
            return	true;

    return	false;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        adj[a][c].push_back(b);
        adj[b][c].push_back(a);
    }
    int	k;
    cin >> k;
    while(k--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        int cnt = 0;
        for (int i = 0; i < m; ++i){
            fill(mark, mark+n, false);
            if (dfs(a, b, i))
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}