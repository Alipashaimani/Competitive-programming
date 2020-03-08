#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int INF = 1e9;
vector<int>adj[MAXN];
int n , m ;
int q[MAXN];
int dis[MAXN];
void bfs(int v){
	int h = 0 , t = 0;
	fill(dis,dis+MAXN,INF);
	dis[v] = 0;
	q[t++] = v;
	while(t-h){
		v = q[h++];
		for (auto u : adj[v]){
			if ( dis[u] == INF){
				q[t++] = u;
				dis[u] = dis[v] + 1;
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1 ; i < MAXN ; i++){
		adj[i].push_back(i-1);
		if ( i * 2 <= MAXN )
		adj[i].push_back(i*2);
	}
	bfs(n);
	cout << dis[m]  << '\n';
	return 0;
}
