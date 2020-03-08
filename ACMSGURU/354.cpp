#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 601;
int mat[maxn][maxn], indeg[maxn][maxn], ans[maxn][maxn];
vector<pii> adj[maxn][maxn];
int a[maxn], seg[maxn * 4];
int n;
queue<pii> Q;

void ERR(int an = 0){
	for(int ancnt = 0; ancnt < an; ancnt++){
		int tmp;
		for(int i = 0; i < n * n; i++)
			scanf("%d", &tmp);
	}
	printf("0\n");
	exit(0);
}

void build(int l = 0, int r = n, int id = 1){
	seg[id] = r - l;
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	return;
}

int get(int k, int l = 0, int r = n, int id = 1){
	seg[id]--;
	if(r - l == 1)
		return l;
	int mid = (l + r) >> 1;
	if(k <= seg[id * 2 + 0])
		return get(k, l, mid, id * 2 + 0);
	return get(k - seg[id * 2 + 0], mid, r, id * 2 + 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", mat[i] + j);
	for(int j = 0; j < n; j++){
		build();
		for(int i = n - 1; i >= 0; i--){
			if(i - mat[i][j] + 1 > seg[1] or i - mat[i][j] + 1 <= 0)
				ERR(1);
			int pos = get(i - mat[i][j] + 1);
			a[pos] = i;
		}
		for(int i = 0; i + 1 < n; i++){
			adj[a[i]][j].PB(MP(a[i + 1], j));
			indeg[a[i + 1]][j]++;
		}
	}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", mat[i] + j);
	for(int i = 0; i < n; i++){
		build();
		for(int j = n - 1; j >= 0; j--){
			if(j - mat[i][j] + 1 > seg[1] or j - mat[i][j] + 1 <= 0)
				ERR();
			int pos = get(j - mat[i][j] + 1);
			a[pos] = j;
		}
		for(int j = 0; j + 1 < n; j++){
			adj[i][a[j]].PB(MP(i, a[j + 1]));
			indeg[i][a[j + 1]]++;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(indeg[i][j] == 0)
				Q.push(MP(i, j));
	int cnt = 0;
	while(Q.size()){
		pii x = Q.front();
		Q.pop();
		ans[x.L][x.R] = ++cnt;
		for(int i = 0; i < adj[x.L][x.R].size(); i++){
			pii y = adj[x.L][x.R][i];
			indeg[y.L][y.R]--;
			if(indeg[y.L][y.R] == 0)
				Q.push(y);
		}
	}
	if(cnt != n * n)
		ERR();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
