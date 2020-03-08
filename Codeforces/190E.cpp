#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 1000;
vector<int> adj[MAXN], com[MAXN];
int nxt[MAXN];
bool mark[MAXN];
int n, m;

int fnxt(int x){return nxt[x] == x ? x : nxt[x] = fnxt(nxt[x]);}

void dfs(int v, int cnt){
    mark[v] = true;
    nxt[v] = v+1;
    com[cnt].push_back(v);

    for(int i = fnxt(1), j = 0; i <= n; i = fnxt(i + 1)){
        while(j < adj[v].size() and adj[v][j] < i)
            j++;
        if(j == adj[v].size() or i != adj[v][j])
            dfs(i, cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n+1; i++)
        nxt[i] = i;

    for (int i = 0, a, b; i < m ; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    int cnt = 0;
    for(int i = fnxt(1); i <= n; i = fnxt(i))
        if(!mark[i])
            dfs(i, cnt++);

    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++){
        cout << com[i].size() << " ";
        for(auto j : com[i])
            cout << j << " " ;
        cout << '\n';
    }
    return 0;
}