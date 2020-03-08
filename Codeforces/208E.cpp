#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10 , lg = 17;

vector <int> adj[MAXN] , str[MAXN] , fns[MAXN] , root;
queue <int> q;
int h[MAXN] , par[MAXN][20] , pt , s[MAXN] , f[MAXN];
bool mark[MAXN];

int findpar(int v , int h){
    for(int i = 0 ; i <= lg ; i++)
        if((1 << i) & h)
            v = par[v][i];

    return v;
}
void dfs(int v , int pos){
    mark[v] = 1;
    h[v] = h[pos] + 1;
    par[v][0] = pos;
    str[h[v]].push_back(pt);
    s[v] = pt++;

    for(int i = 1 ; i <= lg ; i++)
        par[v][i] = par[par[v][i-1]][i-1];

    for(auto u: adj[v])
        if(!mark[u])
            dfs(u,v);

    fns[h[v]].push_back(pt);
    f[v] = pt;
    return;
}

int main(){
    int n;  cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x;  cin >> x;   x--;

        if(x+1){
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        else
            root.push_back(i);
    }

    for(auto i : root)
        dfs(i, i);

    int m;  cin >> m;

    for(int i = 0 ; i < m ; i++){
        int v, p;    cin >> v >> p;  v--;
        if(h[v] <= p)
            cout << "0 ";
        else{
            int k = findpar(v , p);
            int a = lower_bound(str[h[v]].begin() , str[h[v]].end() , s[k]) - str[h[v]].begin();
            int b = upper_bound(fns[h[v]].begin() , fns[h[v]].end() , f[k]) - fns[h[v]].begin();

            cout << b-a-1 << " ";
        }

    }
    return 0;
}