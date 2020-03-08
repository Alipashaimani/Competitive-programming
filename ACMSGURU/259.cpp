#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define L first
#define R second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	pair <ll, ll> a[n];
	rep(i, n)
		cin>>a[i].R;
	rep(i, n)
		cin>>a[i].L;
	
	sort(a, a+n);
	reverse(a, a+n);
	
	ll max_=-100;
	ll time_=0;
	rep(i, n){
		time_+=a[i].R;
		if(time_+a[i].L>max_)
			max_=time_+a[i].L;
	}
	cout<<max_<<endl;
	return 0;
}
