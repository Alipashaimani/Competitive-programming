#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 3;
int a[maxn][maxn], b[maxn][maxn], gcnt[maxn][maxn];
int par[maxn * maxn], val[maxn * maxn], arr[maxn * 4], indeg[maxn * maxn];
vector<int> vert, adj[maxn * maxn], Q;
vector<pii> moja;
int n;

int root(int v){return (par[v] < 0 ? v : par[v] = root(par[v]));}

inline void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

void build(int p = 0){
	if(p == sz(moja)){
		memset(par, -1, sizeof par);
		memset(indeg, 0, sizeof indeg);
		for(int i = 0; i < n * n; i++)
			adj[i].clear();
		vert.clear();

		for(int i = 0; i < sz(moja); i++)
			if(arr[i] == 1)
				merge(moja[i].L, moja[i].R);
		for(int i = 0; i < sz(moja); i++){
			if(arr[i] == 0)
				adj[root(moja[i].L)].PB(root(moja[i].R)), indeg[root(moja[i].R)]++;
			else if(arr[i] == 2)
				adj[root(moja[i].R)].PB(root(moja[i].L)), indeg[root(moja[i].L)]++;
		}
		for(int i = 0; i < n * n; i++)
			if(root(i) == i)
				vert.PB(i);
		for(int i = 0; i < sz(vert); i++)
			if(indeg[vert[i]] == 0)
				Q.PB(vert[i]);
		int seen = 0, cnt = 9;
		while(Q.size()){
			int v = Q.back();
			val[v] = cnt--;
			Q.pop_back();
			seen++;
			for(int i = 0; i < sz(adj[v]); i++){
				int u = adj[v][i];
				indeg[u]--;
				if(indeg[u] == 0)
					Q.push_back(u);
			}
		}
		if(seen != sz(vert))
			return;
		memset(gcnt, 0, sizeof gcnt);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				a[i][j] = val[root(i * n + j)];
				if(i - 1 >= 0){
					if(a[i - 1][j] > a[i][j])
						gcnt[i][j]++;
					else if(a[i - 1][j] < a[i][j])
						gcnt[i - 1][j]++;
				}
				if(j - 1 >= 0){
					if(a[i][j - 1] > a[i][j])
						gcnt[i][j]++;
					else if(a[i][j - 1] < a[i][j])
						gcnt[i][j - 1]++;
				}
			}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(gcnt[i][j] != b[i][j])
					return;
		for(int i = 0; i < n; i++, cout << endl)
			for(int j = 0; j < n; j++, cout << ' ')
				cout << a[i][j];
		exit(0);
		return;		//!!!
	}
	arr[p] = 0;
	build(p + 1);
	arr[p] = 1;
	build(p + 1);
	arr[p] = 2;
	build(p + 1);
	return;
}

int main(){
	vert.reserve(16);
	Q.reserve(16);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> b[i][j];
			if(i + 1 < n)
				moja.PB(MP(i * n + j, (i + 1) * n + j));
			if(j + 1 < n)
				moja.PB(MP(i * n + j, i * n + (j + 1)));
			adj[i * n + j].reserve(9);
		}
	}
	build();
	cout << "NO SOLUTION" << endl;
	return 0;
}
