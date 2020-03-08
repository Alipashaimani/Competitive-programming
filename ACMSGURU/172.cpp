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

int n, m;
const int maxn=1e3;
vector <int> a[maxn];
bool mark[maxn];
int h[maxn];

void dfs(int x){
	mark[x]=true;
	rep(i, a[x].size()){
		int child=a[x][i];
		if(!mark[child]){
			h[child]=h[x]+1;
			dfs(child);
		}
		else if(h[x] % 2 == h[child] % 2){
			cout<<"no"<<endl;
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i, m){
		int se, fi;
		cin>>fi>>se;
		a[fi].pb(se);
		a[se].pb(fi);
	}
	FOR(i, 1, n)
        if(!mark[i])
            dfs(i);
	vector <int> ans;
	FOR(i, 1, n)
		if(h[i]%2==0)
			ans.pb(i);
    cout<<"yes"<<endl;
	cout<<ans.size()<<endl;
	rep(i, ans.size()-1)
		cout<<ans[i]<<' ';
	cout<<ans.back()<<endl;
	return 0;
}
