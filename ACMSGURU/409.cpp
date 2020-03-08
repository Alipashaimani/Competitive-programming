#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
bool ans[maxn * maxn][maxn * maxn];
int n, k;

void Fill(int x, int y){
	int i = y, j = x;
	for(int rem = k; rem > 0; rem--){
		ans[x * n + i][y * n + j] = true;
		j++;
		if(j == n){
			j = 0, i++;
			if(i == n)
				i = 0;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			Fill(i, j);
	for(int i = 0; i < n * n; i++){
		for(int j = 0; j < n * n; j++)
			cout << (ans[i][j] ? '*' : '.');
		cout << '\n';
	}
	return 0;
}
