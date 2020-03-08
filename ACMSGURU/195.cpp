
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smax(x, y) (x) = max((x), (y))

const int maxn = 5e5 + 85 - 69;
vector<int> adj[maxn];
int dp[maxn], pd[maxn], pdman[maxn];
int n;
vector<int> ans;

void dfs(int v){
	for(int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		dfs(u);
		pd[v] += dp[u];
	}
	for(int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if(pd[v] - dp[u] + max(dp[u], pd[u]) > dp[v]){
			dp[v] = pd[v] - dp[u] + max(dp[u], pd[u]);
			if(dp[u] > pd[u])
				pdman[v] = 0;
			else
				pdman[v] = u;
		}
	}
	pd[v]++;
	return;
}

void find_ans(int v, int ty = 0){
	if(ty or pdman[v] == 0){
		if(ty) ans.PB(v);
		for(int i = 0; i < adj[v].size(); i++)
			find_ans(adj[v][i], 0);
		return;
	}
	find_ans(pdman[v], 1);
	for(int i = 0; i < adj[v].size(); i++)
		if(adj[v][i] != pdman[v])
			find_ans(adj[v][i], 0);
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int x;
		scanf("%d", &x);
		adj[x].PB(i);
	}
	dfs(1);
	printf("%d\n", dp[1] * 1000);
	find_ans(1, 0);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
