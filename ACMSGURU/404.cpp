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
	string s[m];
	rep(i, m)
		cin>>s[i];
	n--;
	cout<<s[n%m]<<endl;
	return 0;
}
