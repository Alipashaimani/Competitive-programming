/*
ID: apiv2002
PROG: numtri
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int input[1001][1001];
bool mark[1001][1001];
int answer , n;

int dfs(int x, int y)
{
	if (y == (n - 1))
		return input[x][y];
	if (mark[x][y])
		 return input[x][y];
	input[x][y] = max((input[x][y] + dfs(x, y + 1)), (input[x][y] + dfs(x + 1, y + 1)));
	mark[x][y] = true;
	return input[x][y];
}

int main()
{
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> input[j][i];
	}
	cout << dfs(0, 0) << endl;
	return 0;
}
