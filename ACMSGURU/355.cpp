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

const int maxn=2e4;
int col[maxn];
int color=1;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	col[1]=1;
	FOR(i, 2, n){
		bool mark[50];
		rep(k, 50)
			mark[k]=false;
		for(int j=2; j*j<=i; j++)
			if(i%j==0)
				mark[col[j]]=(mark[col[i/j]]=true);
		FOR(j, 2, 49){
			if(!mark[j]){	
				col[i]=j;
				if(j>color)
					color=j;
				break;
			}
		}
	}
	cout<<color<<endl;
	for(int i=1; i<n; i++)
		cout<<col[i]<<' ';
	cout<<col[n]
		<<endl;
	return 0;
}
