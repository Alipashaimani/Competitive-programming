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
	int S, P;
	cin>>S>>P;
	int d=P-S;
	if(d<=0)
		cout<<0<<endl;
	else if(d<300)
		cout<<1<<endl;
	else if(d<900)
		cout<<2<<endl;
	else if(d<1800)
		cout<<3<<endl;
	else
		cout<<4<<endl;
	return 0;
}
