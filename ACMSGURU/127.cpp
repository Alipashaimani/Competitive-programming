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

int a[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>k>>n;
	rep(i, n){
		string s;
		cin>>s;
		a[s[0]-48]++;
	}
	int ans=0;
	rep(i, 10){
		//cout<<a[i]<<' ';
		ans+=ceil(float(a[i])/k);
	}
	cout<<ans+2<<endl;
	return 0;
}
