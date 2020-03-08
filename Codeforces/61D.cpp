#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
typedef long long ll;

vector < pair<ll,ll> > adj[MAXN];
ll n, t, ans, s;

void dfs(ll v, ll s){
    for(int i = 0 ; i < adj[v].size() ; i++){
        ll u = adj[v][i].first;
        if(u != s){
            t += adj[v][i].second;
            ans = max(ans , t);
            dfs(u , v);
            t -= adj[v][i].second;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        s += c;
    }
    dfs(1, 1);
    cout << 2*s - ans << '\n';
    return 0;
}