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

const int maxn = 2e2 + 10;
vector <int> v[maxn][maxn];
bool mark[maxn][maxn];
vector <int> path;
set <int> ans;
int n, m;

void f(int p, int is){
	if(mark[p][is])
		return;
    mark[p][is] = true;
	if(p == path.size()){
        ans.insert(is);
        return;
    }
    rep(i, v[is][path[p]].size())
        f(p + 1, v[is][path[p]][i]);
}

int main(){
    cin >> n;
    reu(i, 1, n){
        reu(j, 1, n){
            int t;
            scanf("%d", &t);
            v[i][t].pb(j);
            v[j][t].pb(i);
        }
    }
    cin >> m;
    rep(i, m){
        int t;
        cin >> t;
        path.pb(t);
    }
    f(0, 1);
    cout << ans.size() << endl;
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << ' ';
    cout << endl;
	return 0;
}
