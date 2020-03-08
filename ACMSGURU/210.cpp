#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 410;
int match[2][maxn], order[maxn], a[maxn];
vector<int> adj[maxn];
bool mark[maxn];
int n;

bool cmp(int i, int j){return a[i] > a[j];}

bool dfs(int v){
	if(mark[v])
		return false;
	mark[v] = true;
	for(int i = 0; i < sz(adj[v]); i++)
		if(match[1][adj[v][i]] == -1 or dfs(match[1][adj[v][i]])){
			match[0][v] = adj[v][i];
			match[1][adj[v][i]] = v;
			return true;
		}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		order[i] = i;
	}
	sort(order, order + n, cmp);
	
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> cnt;
		while(cnt--){
			int aj;
			cin >> aj;
			adj[i].PB(aj - 1);
		}
	}
	
	memset(match, -1, sizeof match);
	for(int i = 0; i < n; i++){
		memset(mark, false, sizeof mark);
		dfs(order[i]);
	}

	for(int i = 0; i < n; i++)
		cout << (match[0][i] == -1 ? 0 : match[0][i] + 1) << ' ';
	cout << endl;
	return 0;
}
