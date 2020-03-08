/*
ID: apiv2002
PROG: comehome
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int path[54][54];
pair <char, int> answer;
int n;

int main()
{
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	cin >> n;
	answer.second = 1e8;
	for (int i = 0; i < 54; i++)
	{
		for (int j = 0; j < 54; j++)
		{
			path[i][j] = 1e8;
		}
	}
	for (int i = 0; i < n; i++)
	{
		char a, b;
		int c, d, e;
		cin >> a >> b >> c;
		if (a < 'a')
		{
			d = a - 65 + 26;
		}
		else
			d = a - 97;
		if (b < 'a')
		{
			e = b - 65 + 26;
		}
		else
			e = b - 97;
		if (path[d][e] > c)
		{
			path[d][e] = c;
			path[e][d] = c;
		}
	}
	for (int k = 0; k < 52; k++)
	{
		for (int i = 0; i < 52; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				if (path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}
	for (int i = 26; i < 51; i++)
	{
		if (answer.second > path[i][51])
		{
			answer.second = path[i][51];
			answer.first = i + 'A' - 26;
		}
	}
	cout << answer.first << ' ' << answer.second << endl;
	return 0;
}
