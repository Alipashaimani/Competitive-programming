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

const int Ls = 5, L = 1e5;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <int> ans, v;
	if(n < m)
		swap(n, m);
	v.pb(1 << (n % 10));
	rep(i, n/10){
		rep(j, v.size())
			v[j] *= 1024;
		rep(j, v.size() - 1){
			v[j + 1] += v[j] / L;
			v[j] %= L;
		}
		if(v.back() >= L){
			v.pb(v.back() / L);
			v[v.size() - 2] %= L;
		}
	}
	ans = v;
	v.clear();
	v.pb(1 << (m % 10));
	rep(i, m / 10){
		rep(j, v.size())
			v[j] *= 1024;
		rep(j, v.size() - 1){
			v[j + 1] += v[j] / L;
			v[j] %= L;
		}
		if(v.back() >= L){
			v.pb(v.back() / L);
			v[v.size() - 2] %= L;
		}
	}
	ans.pb(0);
	ans[0] -= 2;
	rep(i, v.size()){
		ans[i] += v[i];
		ans[i + 1] += ans[i] / L;
		ans[i] %= L;
	}
	cout << ans[ans.size() - 2];
	for(int i = ans.size() - 3; i >= 0; i--){
		stack <int> S;
		rep(j, Ls){
			S.push(ans[i] % 10);
			ans[i] /= 10;
		}
		while(S.size()){
			cout << S.top();
			S.pop();
		}
	}
	cout << endl;
	return 0;
}
