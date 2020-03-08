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

const int maxn=100;
vector <int> adj[maxn];
bool mark[maxn];
vector <int> ans;

int main(){
	ios_base::sync_with_stdio(false);
	int n, x;
	cin>>n>>x;
	FOR(i, 1, n){
		int t;
		cin>>t;
		rep(j, t){
			int t2;
			cin>>t2;
			adj[i].pb(t2);
		}
	}
	rep(i, adj[x].size()){
		int t=adj[x][i];
		rep(j, adj[t].size())
			mark[adj[t][j]]=true;
	}
	rep(i, adj[x].size())
		mark[adj[x][i]]=false;
	rep(i, maxn)
		if(mark[i] && i!=x)
			ans.pb(i);
	if(ans.size()<1)
		cout<<0<<endl;
	else if(ans.size()==1)
		cout<<ans.size()<<endl<<ans.back()<<endl;
	else{
		cout<<ans.size()<<endl;
		rep(i, ans.size()-1)
			cout<<ans[i]<<' ';
		cout<<ans.back()<<endl;
	}
	return 0;
}
