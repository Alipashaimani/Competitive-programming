#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
vector <int> adj[MAXN];
int mark [MAXN];
bool cat[MAXN];
int n, m, k, ans = 0;
void dfs(int v, int cnt){
	if (cat[v])
		cnt++;

	else
		cnt = 0;

	if ( cnt > k )
		return ;

	if ( adj[v].size() == 1 && v!= 0)
		ans++;


	mark[v] = true;
	for (int i = 0 ; i < adj[v].size() ; i++)
		if (mark[adj[v][i]] == false)
			dfs(adj[v][i],cnt);


}
int main() {
	cin >> n >> k;
	for (int i = 0 ; i < n ; i++)
		cin >> cat[i];

	for (int i = 0 ; i < n-1 ; i++){
		int x,y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0,0);

	cout << ans << '\n';
	return 0;
}
