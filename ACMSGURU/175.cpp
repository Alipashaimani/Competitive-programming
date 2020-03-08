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

int ans=0;

void f(int, int);

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin>>n>>q;
	f(n, q);
	cout<<ans<<endl;
	return 0;
}

void f(int n, int q){
	if(n==1){
		ans++;
		return;
	}
	int k=n/2;
	if(q>k)
		f(n-k, n-q+1);
	else{
		ans+=n-k;
		f(k, k-q+1);
	}
}
