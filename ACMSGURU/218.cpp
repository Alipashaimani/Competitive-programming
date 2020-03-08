#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 510;
vector<pii> adj[maxn];
bool mark[maxn];
int match[2][maxn];
int n;
vector<int> all;

bool cmp(pii x, pii y){
	return x.R < y.R;
}

bool dfs(int v, int maxedge){
	mark[v] = true;
	for(int i = 0; i < n and adj[v][i].R <= maxedge; i++){
		int u = adj[v][i].L;
		if(match[1][u] == -1){
			match[0][v] = u;
			match[1][u] = v;
			return true;
		}
		else if(!mark[match[1][u]] and dfs(match[1][u], maxedge)){
			match[0][v] = u;
			match[1][u] = v;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			all.PB(x);
			adj[i].PB(MP(j, x));
		}
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	int lo = -1, hi = all.size() - 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		bool found;
		int mx = 0;
		memset(match, -1, sizeof match);
		do{
			found = false;
			memset(mark, false, sizeof mark);
			for(int i = 0; i < n; i++){
				if(!mark[i] and match[0][i] == -1)
					if(dfs(i, all[mid])){
						mx++;
						found = true;
					}
			}
		}while(found);
		if(mx == n)
			hi = mid;
		else
			lo = mid;
	}
	bool found;
	int mx = 0;
	memset(match, -1, sizeof match);
	do{
		found = false;
		memset(mark, false, sizeof mark);
		for(int i = 0; i < n; i++){
			if(!mark[i] and match[0][i] == -1)
				if(dfs(i, all[hi])){
					mx++;
					found = true;
				}
		}
	}while(found);
	cout << all[hi] << '\n';
	for(int i = 0; i < n; i++)
		cout << i + 1 << ' ' << match[0][i] + 1 << '\n';
	return 0;
}
