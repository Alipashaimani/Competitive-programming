#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

ll C(ll n, ll r){
	ll ans=1;
	FOR(i, r+1, n){
		ans*=i;
		ans/=i-r;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	if(k>n){
		cout<<0<<endl;
		return 0;
	}
	ll ans=1;
	FOR(i, n-k+1, n)
		ans*=i;
	ans*=C(n, k);
	cout<<ans<<endl;
	return 0;
}
