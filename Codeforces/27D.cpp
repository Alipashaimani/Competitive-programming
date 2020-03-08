#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 200;

int n, m, mn[MAXN], mx[MAXN] ;
vector<int>adj[MAXN] ;
bool mark[MAXN], part[MAXN], flag;

void dfs(int u , bool color){
    mark[u] = true ;
    part[u] = color ;

    for(auto v : adj[u]){
        if(mark[v] && part[v] == color){
            flag = true;
            return ;
        }
        if(!mark[v])
            dfs(v, !color) ;
    }
}

int main(){
    cin >> n >> m ;
    for(int i = 0; i < m; i++){
        int x, y ;  cin >> x >> y ;x--,y--;
        mn[i] = min(x, y);
        mx[i] = max(x, y);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(mn[i] < mn[j] && mn[i] < mx[i] && mn[i] < mx[j]  && mn[j] < mx[i] && mn[j] < mx[j]&& mx[i] < mx[j] ){
                adj[i].push_back(j) ;
                adj[j].push_back(i) ;
            }
        }
    }

    for(int i = 0; i < m; i++)
        if(!mark[i]){
            dfs(i , 0);
            if (flag)
                return cout << "Impossible\n" ,0;
        }

    for(int i=0 ; i<m ; i++)
        cout<<(part[i] ? 'o' : 'i') ;
}