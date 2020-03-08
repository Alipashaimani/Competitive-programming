#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100 ;
vector<int>adj[MAXN];
int color[MAXN];
vector<pair<int,int> > edge;
bool mark[MAXN];
bool flag = 0;
void dfs(int v,int f){
    mark[v] = true;
    for (auto i : adj[v]){
        if (v != f && i != f && !mark[i]){
            if (color[i] != color[v]){
                flag = 1;
                return;
            }
            dfs(i, f);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for ( int i = 0 ; i < n-1 ; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        edge.push_back({x,y});
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    for ( int i = 0 ; i < n ; i++){
        cin >> color[i];
    }
    int p1 = -1, p2 = -1;
    for (int i = 0 ; i < edge.size() ; i++){
        if (color[edge[i].first] != color[edge[i].second]){
            p1 = edge[i].first;
            p2 = edge[i].second;
            break;
        }
    }

    if (p1 == -1)
        return cout << "YES\n" << 1 << '\n' , 0;

    for (int i = 0 ; i < n ; i++){
        flag = 0;
        dfs(i,p1);
        if (flag)
            goto hell;
    }
    return cout << "YES\n" << ++p1 << '\n' , 0 ;

hell:
    memset(mark, 0, sizeof(mark));
           for(int i = 0 ; i < n ; i++){
               flag = 0;
               dfs(i,p2);
               if(flag)
                   goto heven;
           }
           return cout << "YES\n" << ++p2 << '\n' , 0 ;

           heven:

           return cout << "NO\n" , 0;


           }
