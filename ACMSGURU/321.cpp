#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 2e5 + 100;
pie par[maxn];
vector<pair<int, pie> > v[maxn];
int n, h = -1, alp;
deque <int> D;
bool mark[maxn];
vector<int> ans;

void dfs(int x){
	mark[x] = true;
	h ++;
	if(par[x].p1 == 1){
		alp ++;
		D.push_front(x);
	}
	//cerr << x << endl;
	//cerr << '\t' << h << ' ' << alp << endl;
	while(alp > h / 2){
		alp --;
		int y = D.back();
		D.pop_back();
		par[y].p1 = 2;
		ans.PB(par[y].p2);
	}
	//cerr << '\t' << h << ' ' << alp << endl;

	rep(i, v[x].size()){
		int ch = v[x][i].p1;
		if(mark[ch])
			continue;
		par[ch] = MP(v[x][i].p2.p1, v[x][i].p2.p2);
		dfs(ch);
	}

	if(par[x].p1 == 1 and D.size() and D.front() == x){
		D.pop_front();
		alp --;
	}
	h --;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	rer(i, 1, n){
		int fi, se;
		string th;
		cin >> fi >> se >> th;
		if(th[0] == 'a'){
			cin >> th;
			v[fi].PB(MP(se, MP(1, i)));
			v[se].PB(MP(fi, MP(1, i)));
		}
		else{
			v[fi].PB(MP(se, MP(2, i)));
			v[se].PB(MP(fi, MP(2, i)));
		}
	}
	dfs(1);
	cout << ans.size() << endl;
	rep(i, ans.size())
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
