#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (s); (i) <= (e); (i)++)
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

const int maxn = 1.6e4 + 100;
bool mark[maxn];
vector <int> v[maxn];
ll dp[maxn], pd[maxn];
ll scr[maxn];
ll n;

void dfs(int x){
	mark[x] = true;
	dp[x] = scr[x];
	rep(i, v[x].size()){
		if(!mark[v[x][i]]){
			dfs(v[x][i]);
			if(dp[v[x][i]] > 0)
				dp[x] += dp[v[x][i]];
			pd[x] = max(pd[x], max(dp[v[x][i]], pd[v[x][i]]));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	bool cheese = true;
	ll Max = -1000000;
	reu(i, 1, n){
		cin >> scr[i];
		if(scr[i] >= 0)
			cheese = false;
		Max = max(Max, scr[i]);
	}
	reu(i, 2, n){
		int fi, se;
		cin >> fi >> se;
		v[fi].pb(se);
		v[se].pb(fi);
	}
	if(cheese){
		cout << Max << endl;
		return 0;
	}
	dfs(1);
	cout << max(dp[1], pd[1]) << endl;
	return 0;
}
