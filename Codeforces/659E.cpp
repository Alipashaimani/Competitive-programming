#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
vector<int> adj[MAXN];
int lcm (int a, int b){return (a*b)/__gcd(a,b);}
bool mark[MAXN];
int ans = 0;
int Cvertex = 0;
int Cedge = 0;
int n,m;
void dfs(int vertex){
    mark[vertex] = true;
    Cvertex++;
    Cedge += adj[vertex].size();
    for ( int i = 0 ; i < adj[vertex].size() ; i++){
        if (!mark[adj[vertex][i]])
            dfs(adj[vertex][i]);
    }
}
bool flag = false;
int main(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for ( int i = 0 ; i < n ; i++)
        if (!mark[i]){
            Cvertex = 0; Cedge = 0;
            dfs(i);
            if ( (Cedge / 2) + 1 == Cvertex){
                ans ++;
            }
        }
    cout << ans << '\n';
}
