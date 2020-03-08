#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;
typedef vector<ll> Bignum;

Bignum f, g, tmp;
const ll Base = 1e5;

Bignum sum(Bignum a, Bignum b){
	Bignum c;
	int car = 0;
	for(int i = 0, j = 0; i < a.size() or j < b.size() or car; i++, j++){
		ll cur = car;
		if(i < a.size())
			cur += a[i];
		if(j < b.size())
			cur += b[j];
		c.PB(cur % Base);
		car = cur / Base;
	}
	return c;
}

Bignum mul(Bignum a, ll x){
	rep(i, a.size())
		a[i] *= x;
	ll car = 0;
	rep(i, a.size()){
		ll cur = a[i] + car;
		a[i] = cur % Base;
		car = cur / Base;
	}
	while(car){
		a.PB(car % Base);
		car /= Base;
	}
	return a;
}

int main(){
	//ios_base::sync_with_stdio(false);
	string s;
	int n, m;
	cin >> n >> m;
	g.PB(1);
	f.PB(0);
	reu(i, 1, m){
		tmp = sum(g, mul(f, 2));
		g = mul(f, n);
		f = tmp;
	}
	reverse(g.begin(), g.end());
	int p = 0;
	while(g[p] == 0 and p < g.size() - 1)
		p++;
	printf("%lld", g[p]);
	p++;
	rer(i, p, g.size()){
		if(g[i] >= 1e4)
			printf("%lld", g[i]);
		else if(g[i] >= 1e3)
			printf("0%lld", g[i]);
		else if(g[i] >= 1e2)
			printf("00%lld", g[i]);
		else if(g[i] >= 1e1)
			printf("000%lld", g[i]);
		else
			printf("0000%lld", g[i]);
	}
	printf("\n");
	return 0;
}
