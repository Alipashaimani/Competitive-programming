/*
ID: apiv2002
PROG: subset
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int n, valn;
long long answers;
long long dp[40][391];

int main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	cin >> n;
	valn = (n * (n + 1) / 2);
	if (valn % 2)
	{
		cout << 0 << endl;
		return 0;
	}
	valn /= 2;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= valn; j++)
		{
			if (j < i) { dp[i][j] = dp[i - 1][j]; }
			if (j == i) { dp[i][j] = dp[i - 1][j] + 1; }
			if (j > i) { dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i]; }
		}
	}
	cout << (dp[n][valn] / 2) << endl;
	return 0;
}
