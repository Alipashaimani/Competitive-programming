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

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	int ans=0;
	rep(i, m){
		int x;
		cin>>x;
		ans+=x;
		ans%=n;
	}
	cout<<ans<<endl;
	return 0;
}
