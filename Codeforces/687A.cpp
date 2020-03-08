#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
vector <int> adj[MAXN];
int mark [MAXN];
bool color[MAXN];
int m,n;
void dfs (int v){
	mark[v] = true;
	for (int u : adj[v]){
		if (mark[u] == false){
			color[u] = !color[v];
			dfs(u);
		}

		if (color[u] == color[v]){
			cout << -1 << '\n' ;
			exit(0);
		}

	}
}
int main(){
	cin >> n >> m;
	for ( int i = 0 ; i < m ;i++){
		int x,y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0 ; i < n ; i++)
		if (!mark[i])
			dfs(i);

	int black = 0;
	int white = 0;
	for ( int i = 0 ; i < n ; i++){
		if (color[i])
			black++;
		else
			white++;
	}
	cout << black << '\n' ;
	for ( int i = 0 ; i < n ; i++)
		if (color[i])
			cout << i+1 << " ";
	cout << '\n' << white << '\n';
	for ( int i = 0 ; i < n ; i++)
		if(!color[i])
			cout << i+1 << " ";
	cout << '\n';

}
