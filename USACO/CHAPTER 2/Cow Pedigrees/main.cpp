/*
ID: apiv2002
PROG: nocows
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int dp[101][201];
int n, k;
const int MODULO = 9901;

int main()
{
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i <= k; i++) dp[i][1] = 1;
	for (int i = 2; i <= k; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			for (int z = 1; z <= j - 2 ; z++)
			{
				dp[i][j] += (dp[i - 1][z] * dp[i - 1][j - z - 1] % MODULO);
				dp[i][j] %= MODULO;
			}
		}
	}
	cout << (dp[k][n] - dp[k - 1][n] + MODULO) % MODULO << endl;
	cin >> k;
	return 0;
}