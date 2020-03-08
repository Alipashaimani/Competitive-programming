#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 25;
LL dp[maxn][10];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= 20; i++)
		for(int j = 0; j < 10; j++)
			for(int jj = 0; jj <= j; jj++)
				dp[i][j] += dp[i - 1][jj];
	LL ans = 0;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < 10; j++)
			for(int jj = 0; jj < j; jj++)
				ans += dp[i][j] * dp[n - i][jj];
	for(int j = 0; j < 10; j++)
		ans += dp[n][j];
	cout << ans << endl;
	return 0;
}
