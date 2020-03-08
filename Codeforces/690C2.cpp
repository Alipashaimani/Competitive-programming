#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
vector <int> adj[MAXN];
int mark [MAXN], d = 0, k = 1;
int n ,m;

void dfs1(int a, int c, int KK) {
	mark[a] = KK;
	for (int i = 0; i < adj[a].size(); ++i) {
		if (mark [adj[a][i]] != KK) {
			dfs1(adj[a][i], c + 1, KK);
		}
		if (d <= c) {
			k = a;
			d = max(d, c);
		}
	}
}

int main() {
        cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x,y;
		cin >> x >>y;
		x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
   }
    dfs1(0, 0, 1);
    dfs1(k, 0 , 2);
    cout << d << '\n';
    return 0;
}
