#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 100;
vector<int>adj[MAXN];
int sz[MAXN];
bool mark[MAXN];
char ans[MAXN];
void get_sz(int v, int p = -1){
    sz[v] = 1;
    for (auto i : adj[v]){
        if (!mark[i] && p != i){
            get_sz(i, v);
            sz[v] += sz[i];
        }
    }
}
void dfs(int v = 0, char c = 'A'){
    get_sz(v);
    int r = v;
    int par = -1;
    bool issentroid = true;

    while(issentroid){
        issentroid = false;
        for (auto i : adj[r]){
            if (sz[i] > sz[v] / 2 && i != par && !mark[i]){
                par = r;
                r = i;
                issentroid = true;
                break;
            }
        }
    }
    ans[r] = c;
    mark[r] = true;
    for (auto i : adj[r]){
        if (!mark[i]){
            dfs(i, c+1);
        }
    }
}
int main(){
    int  n; cin >> n;
    for (int i = 0 ; i < n - 1 ; i++){
        int x,y;    cin >> x >> y;  x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fill(ans,ans + MAXN , '*');
    dfs();
    for (int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
}
