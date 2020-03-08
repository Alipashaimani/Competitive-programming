#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e4 + 10;
vector <pie> v[maxn];
pie par[maxn];
ll dp_up[maxn], dp_down[maxn];

void dfs_down(int x){
    rep(i, v[x].size()){
        dfs_down(v[x][i].p1);
        dp_down[x] = max(dp_down[v[x][i].p1] + v[x][i].p2, dp_down[x]);
    }
}

void dfs_up(int x){
    if(x != 1){
        dp_up[x] = dp_up[par[x].p1] + par[x].p2;
        int p = par[x].p1;
        rep(i, v[p].size())
            if(v[p][i].p1 != x)
                dp_up[x] = max(dp_up[x], dp_down[v[p][i].p1] + v[p][i].p2 + par[x].p2);
    }
    rep(i, v[x].size())
        dfs_up(v[x][i].p1);
}

int main(){
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    reu(i, 2, n){
        int fi, se;
        cin >> fi >> se;
        par[i] = mp(fi, se);
        v[fi].pb(mp(i, se));
    }
    dfs_down(1);
    dfs_up(1);
    reu(i, 1, n)
        cout << max(dp_down[i], dp_up[i]) << endl;
	return 0;
}
