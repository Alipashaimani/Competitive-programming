#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1000;
int n, m, a[maxn][maxn], color[maxn * maxn];
bool mark[51];
vector<int> adj[maxn * maxn], v;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%d", a[i] + j);
			v.PB(a[i][j]);
		}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++) if(a[0][j] != a[i][j]){
			int id1 = lower_bound(v.begin(), v.end(), a[0][j]) - v.begin(),
				id2 = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
			adj[max(id1, id2)].PB(min(id1, id2));
			break;
		}
	}
	printf("Yes\n");
	for(int i = 0; i < sz(v); i++){
		memset(mark, false, sizeof mark);
		for(int j = 0; j < sz(adj[i]); j++)
			mark[color[adj[i][j]]] = true;
		for(int j = 0; j <= 50; j++)
			if(!mark[j]){
				printf("%d -> %d\n", v[i], j);
				color[i] = j;
				break;
			}
	}
	return 0;
}
