/*
ID: apiv2002
PROG: castle
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

struct sans
{
	int i = 100;
	int j = 100;
	char k = 'E';
};
vector < pair<int, int> > node[51][51];
vector <int> answers;
int  abstraction[51][51];
int m, n, color = 1, maxroom = 0, maxpair = 0;
sans secans;

void cmp(int a, int b, char c , int local)
{
	if (local > maxpair)
	{
		maxpair = local;
		secans.i = a;
		secans.j = b;
		secans.k = c;
	}
	if (b < secans.j)
	{
		secans.i = a;
		secans.j = b;
		secans.k = c;
	}
	if (b == secans.j)
	{
		if (a > secans.i)
		{
			secans.i = a;
			secans.j = b;
			secans.k = c;
		}
		if (a == secans.i)
		{
			if (c == 'N')
			{
				secans.i = a;
				secans.j = b;
				secans.k = c;
			}
		}
	}
}
int dfs(int x, int y, int col)
{
	int answer = 1;
	abstraction[x][y] = col;
	for (int i = 0; i < node[x][y].size(); i++)
	{
		if (!abstraction[node[x][y][i].first][node[x][y][i].second])
			answer += dfs(node[x][y][i].first, node[x][y][i].second, col);
	}
	return answer;
}

int main()
{
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if ((a - 8) < 0) { node[i][j].push_back(make_pair(i + 1, j)); }
			else { a -= 8;}
			if ((a - 4) < 0) { node[i][j].push_back(make_pair(i, j + 1)); }
			else { a -= 4;}
			if ((a - 2) < 0) { node[i][j].push_back(make_pair(i - 1, j)); }
			else { a -= 2;}
			if ((a - 1) < 0) { node[i][j].push_back(make_pair(i, j - 1)); }
			else { a -= 1;}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!abstraction[i][j])
			{
				int ans = dfs(i, j, color++);
				if (ans > maxroom)
					maxroom = ans;
				answers.push_back(ans);
			}
		}
	}
	cout << --color << endl;
	cout << maxroom << endl;
	//cout << answers[abstraction[1][2] - 1] << answers[abstraction[1][3] - 1] << endl;
	for (int i = 1; i < n; i++)
	{
		//cout << (answers[abstraction[1][i] - 1] + answers[abstraction[1][i + 1] - 1]) << endl;
		if ((answers[abstraction[1][i] - 1] + answers[abstraction[1][i + 1] - 1]) >= maxpair && (abstraction[1][i] != abstraction[1][i + 1]))
			cmp(1, i, 'E' , (answers[abstraction[1][i] - 1] + answers[abstraction[1][i + 1] - 1]));
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			//cout << (answers[abstraction[i][j] - 1] + answers[abstraction[i][j + 1] - 1]) << " : " << (answers[abstraction[i][j] - 1] + answers[abstraction[i - 1][j] - 1]) << endl;
			if ((answers[abstraction[i][j] - 1] + answers[abstraction[i][j + 1] - 1]) >= maxpair && (abstraction[i][j] != abstraction[i][j + 1]))
				cmp(i, j, 'E', (answers[abstraction[i][j] - 1] + answers[abstraction[i][j + 1] - 1]));
			if ((answers[abstraction[i][j] - 1] + answers[abstraction[i - 1][j] - 1]) >= maxpair && (abstraction[i][j] != abstraction[i - 1][j]))
				cmp(i, j, 'N', (answers[abstraction[i][j] - 1] + answers[abstraction[i - 1][j] - 1]));
		}
	}
	for (int i = 2; i <= m; i++)
	{
		//cout << (answers[abstraction[i][n] - 1] + answers[abstraction[i - 1][n] - 1]) << endl;
		if ((answers[abstraction[i][n] - 1] + answers[abstraction[i - 1][n] - 1]) >= maxpair && (abstraction[i][n] != abstraction[i - 1][n]))
			cmp(i, n, 'N', (answers[abstraction[i][n] - 1] + answers[abstraction[i - 1][n] - 1]));
	}
	cout << maxpair << endl;
	cout << secans.i << ' ' << secans.j << ' ' << secans.k << endl;
	return 0;
}
