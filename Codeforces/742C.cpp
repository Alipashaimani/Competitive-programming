#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4;
vector<int> adj[MAXN];
int lcm (int a, int b){return (a*b)/__gcd(a,b);}
bool mark[MAXN];
int ans = 0;
int cnt = 0;
void dfs(int vertex){
    mark[vertex] = true;
    cnt++;
    for ( int i = 0 ; i < adj[vertex].size() ; i++){
        if (!mark[adj[vertex][i]])
            dfs(adj[vertex][i]);
    }
}
bool flag = false;
int main(){
    int n; cin >> n;
    for ( int i = 0 ; i < n ; i++){
        int x;
        cin >> x; x--;
        adj[x].push_back(i);
    }

    for ( int i = 0 ; i < n ; i++)
        if ( adj[i].size() != 1)
            return cout << -1 << '\n' , 0;

    for ( int i = 0 ; i < n ; i++)
        if (!mark[i]){
            cnt = 0;
            dfs(i);
            if (!(cnt & 1))
                cnt /= 2;

            if (flag == false){
                ans = cnt;
                flag = true;
            }
            else
                ans = lcm(ans,cnt);
        }
    cout << ans << '\n';
}
