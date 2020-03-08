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

int hit[10], scr[10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	rep(i, n+1)
		hit[i]=100;
	rep(i, m){
		int a, b;
		cin>>a>>b;
		if(hit[a]>0){
			if(hit[b]>0)
				scr[a]+=3;
			hit[b]-=8;
		}
	}
	rep(i, n+1)
		scr[i]+=max(0, hit[i]/2);
	FOR(i, 1, n)
		cout<<hit[i]<<' '<<scr[i]<<endl;
	return 0;
}
