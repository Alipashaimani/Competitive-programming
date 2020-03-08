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
	int a[3][3];
	int b[3];
	rep(i, 3)
		rep(j, 3)
			cin>>a[i][j];
	rep(i, 3){
		sort(a[i], a[i]+3);
		b[i]=a[i][1];
	}
	sort(b, b+3);
	cout<<b[1]<<endl;
	return 0;
}
