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
typedef pair<int, ll> pie;

const int maxn = 300 + 50;
int n, m, s, e;
vector<pie> v[maxn];
ll d[maxn];
pair<bool, int> init[maxn];
int rb[maxn], rp[maxn], par[maxn];

bool col(int x, ll t){
	if(t <= init[x].p2)
		return init[x].p1;
	t -= init[x].p2;
	t %= rb[x] + rp[x];
	if(t == 0)
		return init[x].p1;
	if(init[x].p1){
		if(t <= rp[x])
			return false;
		return true;
	}
	if(t <= rb[x])
		return true;
	return false;
}

ll F(int x, int y, ll t){
	ll LCM = (rb[x] + rp[x]) * (rb[y] + rp[y]) / __gcd(rb[x] + rp[x], rb[y] + rp[y]);
	reu(i, 1, LCM)
		if(col(x, i + t) == col(y, i + t))
			return i + t - 1;
	return -1;
}

void print(int x = e){
	if(x == s){
		cout << s << ' ';
		return;
	}
	print(par[x]);
	cout << x << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s >> e
		>> n >> m;
	reu(i, 1, n){
		d[i] = 5e17;
		char c;
		int x;
		cin >> c;
		if(c == 'B')
			init[i].p1 = true;
		else
			init[i].p1 = false;
		cin >> x;
		init[i].p2 = x;
		cin >> x;
		rb[i] = x;
		cin >> x;
		rp[i] = x;
	}
	reu(i, 1, m){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi].pb(mp(se, th));
		v[se].pb(mp(fi, th));
	}
	set <pair<ll, int> > S;
	S.insert(mp(0, s));
	d[s] = 0;
	while(S.size()){
		int x = S.begin() -> p2;
		cerr << x << ' ' << (S.begin() -> p1) << endl;
		S.erase(S.begin());
		if(x == e){
			cout << d[e] - d[s] << endl;
			print();
			cout << endl;
			return 0;
		}
		rep(i, v[x].size()){
			if(T == d[x] && TT != d[x] + 1){
				T = TT;
				cerr << x << ' ' << v[x][i].p1 << ' ' << d[x] << endl;
			}
			
			if(T == -1)
				continue;
			if(T + v[x][i].p2 < d[v[x][i].p1]){
				S.erase(mp(d[v[x][i].p1], v[x][i].p1));
				par[v[x][i].p1] = x;
				d[v[x][i].p1] = T + v[x][i].p2;
				S.insert(mp(d[v[x][i].p1], v[x][i].p1));
			}
		}
	}
	cout << 0 << endl;
	return 0;
}
