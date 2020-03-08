#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 310;
bool mark[maxn];
LL a[maxn], b[maxn];
vector<LL> all, adj[maxn];
LL match[2][maxn * maxn * 2];
LL n, m;

bool dfs(int v){
	if(mark[v])
		return false;
	mark[v] = true;
	for(int i = 0; i < sz(adj[v]); i++){
		int u = adj[v][i];
		if(match[1][u] == -1 or dfs(match[1][u])){
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
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		if(a[i] > 0){
			LL val = b[i];
			if(val <= 0){
				val %= a[i];
				if(val <= 0)
					val += a[i];
			}
			for(int k = 1; k <= 310 and val <= m; k++, val += a[i])
				all.PB(val), adj[i].PB(val);
		}
		else if(a[i] == 0){
			if(b[i] >= 1 and b[i] <= m)
				all.PB(b[i]), adj[i].PB(b[i]);
		}
		else{
			a[i] = -a[i];
			LL val = m - b[i] + 1;
			if(val <= 0){
				val %= a[i];
				if(val <= 0)
					val += a[i];
			}
			for(int k = 1; k <= 310 and val <= m; k++, val += a[i])
				all.PB(m + 1 - val), adj[i].PB(m + 1 - val);
		}
	}

	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());

	for(int i = 0; i < n; i++)
		for(int j = 0; j < sz(adj[i]); j++)
			adj[i][j] = lower_bound(all.begin(), all.end(), adj[i][j]) - all.begin();

	memset(match, -1, sizeof match);
	for(int i = 0; i < n; i++) if(match[0][i] == -1){
		memset(mark, false, sizeof mark);
		dfs(i);
	}

	memset(mark, false, sizeof mark);
	for(int i = 0; i < n; i++)
		if(match[0][i] != -1 and all[match[0][i]] < 310)
			mark[all[match[0][i]]] = true;

	int pos = 1;
	for(int i = 0; i < n; i++){
		if(match[0][i] != -1)
			cout << all[match[0][i]] << ' ';
		else{
			while(mark[pos]) pos++;
			mark[pos] = true;
			cout << pos << ' ';
		}
	}
	cout << '\n';

	return 0;
}
