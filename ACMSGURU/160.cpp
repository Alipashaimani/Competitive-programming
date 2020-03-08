#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 10, maxm = 1000 + 10;
bool can[maxn][maxm];
int par[maxn][maxm];
int a[maxn];
int n, m;

void print(int row, int col){
	if(row == 0)
		return;
	if(par[row][col] == col)
		return print(row - 1, col);
	print(row - 1, par[row][col]);
	printf("%d ", row);
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	can[0][1] = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) if(can[i][j]){
			can[i + 1][j] = true;
			par[i + 1][j] = j;
			if(!can[i + 1][(j * a[i]) % m]){
				can[i + 1][(j * a[i]) % m] = true;
				par[i + 1][(j * a[i]) % m] = j;
			}
		}
	}
	for(int j = m - 1; j >= 0; j--)
		if(can[n][j]){
			printf("%d\n", j);
			print(n, j);
			printf("\n");
			break;
		}
	return 0;
}
