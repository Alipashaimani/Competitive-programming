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

bool isprime(int a){
	if(a<=1)
		return false;
	for(int i=2; i*i<=a; i++)
		if(a%i==0)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n<5){
		cout<<0<<endl;
		return 0;
	}
	vector <int> ans;
	ans.pb(3);
	for(int b=5; b<=n-2; b+=6)
		if(isprime(b) && isprime(b+2))
			ans.pb(b);
	cout<<ans.size()<<endl;
	rep(i, ans.size())
		printf("2 %d\n", ans[i]);
	return 0;
}
