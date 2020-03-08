#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 100;
vector<int> adj[MAXN], weight[MAXN] ,ans;
int n;
bool mark[MAXN];

bool dfs(int v){
    bool flag = false;
    mark[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        if(!mark[adj[v][i]]){
            if(dfs(adj[v][i]))
                flag = true;
            else if(weight[v][i] == 2){
                ans.push_back(adj[v][i]);
                flag = true;
            }
        }
    }
    return flag;
}

int main(){
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);adj[y].push_back(x);
        weight[x].push_back(z);weight[y].push_back(z);
    }
    dfs(1);

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}