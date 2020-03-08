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

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 5e4 + 10;
int par[maxn], ind[maxn], val[maxn], n, m;
vector <int> v[maxn];
set <int> s[maxn];

void dfs(int x){
	rep(i, v[x].size()){
		dfs(v[x][i]);
		val[x] = min(val[x], val[v[x][i]]);
	}

	rep(i, v[x].size()){
		int t = v[x][i];
		if(ind[t] == ind[x])
			continue;
		while(s[ind[t]].size()){
			int a = *s[ind[t]].begin();
			set<int>::iterator it;
			it = s[ind[x]].lower_bound(a);
			if(it != s[ind[x]].end())
				val[x] = min(val[x], (*it) - a);
			if(it != s[ind[x]].begin()){
				it --;
				val[x] = min(val[x], a - (*it));
			}
			s[ind[x]].insert(a);
			s[ind[t]].erase(s[ind[t]].begin());
		}
	}

	if(par[x] != 0)
		if(s[ind[x]].size() > s[ind[par[x]]].size())
			ind[par[x]] = ind[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	val[1] = 2147483647;
	reu(i, 2, n){
		int p;
		cin >> p;
		par[i] = p;
		v[p].pb(i);
		val[i] = 2147483647;
	}
	int p = 1;
	reu(i, 1, m){
		int x;
		cin >> x;
		while(v[p].size() != 0) p ++;
		s[i].insert(x);
		ind[p] = i;
		p ++;
	}
	dfs(1);
	reu(i, 1, n)
		if(v[i].size())
			cout << val[i] << ' ';
	cout << endl;
	return 0;
}
