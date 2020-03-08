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
	int n;
	cin>>n;
	if(n<9)
		cout<<0<<endl;
	else if(n==9)
		cout<<8<<endl;
	else{
		cout<<72;
		rep(i, n%10)
			cout<<0;
		rep(i, (n-10)/10)
			cout<<"0000000000";
		cout<<endl;
	}
	return 0;
}
