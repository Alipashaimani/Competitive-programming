/*
ID: apiv2002
PROG: money
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

long long dp[27][10002];
int vals[26];
int n, v;

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin >> v >> n;
	for (int i = 1; i <= v; i++) { cin >> vals[i]; }
	for (int i = 0; i <= v; i++) { dp[i][0] = 1; }
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; (k * vals[i]) <= j; k++)
			{
				dp[i][j] += dp[i - 1][j - (k * vals[i])];
			}
		}
	}
	cout << dp[v][n] << endl;
	return 0;
}