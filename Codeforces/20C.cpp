#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 100;
const ll oo = 1e12;
vector<pair<ll,ll> > adj[MAXN];
set <pair<ll ,ll> > st;

ll d[MAXN];
ll n,m;
ll par[MAXN];
void dij(ll v) {

    fill(d, d+n, oo);
    fill(par, par+n, -1);

    d[v] = 0;

    st.insert({d[v], v});

    while (st.size()) {
        ll u = st.begin() -> second;
        st.erase(st.begin());
        for (auto p : adj[u]) {
            if (d[p.first] > d[u] + p.second) {
                st.erase({d[p.first] , p.first});
                d[p.first] = d[u] + p.second;
                par[p.first] = u;
                st.insert({d[p.first] , p.first});
            }
        }
    }
}

void prll(ll x){
    if (par[x]!= -1)
        prll(par[x]);
    cout << x+1 << " " ;

}
int main(){
    cin >> n >> m;
    for ( ll i = 0 ; i < m ; i++){
        ll x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    dij(0);
    if (d[n-1] == oo)
        return cout << -1 << " " ,0;
    prll(n-1);
}
