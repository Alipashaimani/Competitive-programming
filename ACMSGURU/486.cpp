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

bool mark[10];

int main(){
	ios_base::sync_with_stdio(false);
	char a[4], b[4];
	cin>>a;
	cin>>b;
	rep(i, 4)
		mark[a[i]-48]=true;
	int ans1=0, ans2=0;
	rep(i, 4){
		if(mark[b[i]-48]){
			if(a[i]==b[i])
				ans1++;
			else
				ans2++;
		}
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}
