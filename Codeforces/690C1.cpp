/*
ID: apiv2002
PROG: butter
LANG: C++14
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 100;
vector<int> adj[MAXN];
bool mark[MAXN];
int m,n;
void dfs(int v){
	mark[v] = true;
	for ( int i = 0 ; i < adj[v].size() ; i++){
		if ( mark[adj[v][i]] == false)
			dfs(adj[v][i]);
	}
}
bool check(){
	for ( int i = 0 ; i < n ; i++ )
		if ( mark[i] == false )
			return false;

		return true;
}
int main(){

	cin >> n >> m;
	for ( int i = 0 ; i < m ; i++){
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0);
	if ( check() && m+1 == n)
		cout << "yes\n";
	else
		cout << "no\n";

}
