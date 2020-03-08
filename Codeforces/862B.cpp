#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a , b, l , r , mark[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int color)
{
	mark[v] = color;
	if (color == 1)
	{
		l++;
		color = 2;
	}
	else
	{
		r++;
		color = 1;
	}
	for (auto i : adj[v])
	{
		if (!mark[i])
		{
			dfs(i, color);
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	dfs(1 , 1);
	cout << ((long long)l) * ((long long)r) - n + 1 << endl;
	return 0;
}