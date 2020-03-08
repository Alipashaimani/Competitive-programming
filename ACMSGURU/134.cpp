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

const int maxn = 1.6e4 + 100;
int dwn[maxn], up[maxn];
int scr[maxn], par[maxn];
vector <int> v[maxn];
int n;

void DWN(int x){
	dwn[x] = 1;
	rep(i, v[x].size()){
		if(v[x][i] != par[x]){
			par[v[x][i]] = x;
			DWN(v[x][i]);
			dwn[x] += dwn[v[x][i]];
		}
	}
}

void UP(int x){
	rep(i, v[x].size()){
		if(up[v[x][i]] == 0 && v[x][i] != 1){
			up[v[x][i]] = dwn[x] - dwn[v[x][i]] + up[x];
			UP(v[x][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	reu(i, 2, n){
		int fi, se;
		cin >> fi >> se;
		v[fi].pb(se);
		v[se].pb(fi);
	}
	DWN(1);
	UP(1);
	reu(i, 1, n)
		cerr << dwn[i] << ' ' << up[i] << ' ' << par[i] << endl;
	int Min = 2e9;
	reu(i, 1, n){
		int Max = up[i];
		rep(j, v[i].size())
			if(v[i][j] != par[i])
				Max = max(Max, dwn[v[i][j]]);
		scr[i] = Max;
		if(Max < Min)
			Min = Max;
	}
	vector <int> ans;
	reu(i, 1, n)
		if(scr[i] == Min)
			ans.pb(i);
	cout << Min << ' ' << ans.size() << endl;
	rep(i, ans.size())
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
