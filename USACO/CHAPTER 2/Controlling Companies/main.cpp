/*
ID: apiv2002
PROG: concom
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int persent[101][101];
int par[101][101];
bool mark[101][101];
vector < pair<int, int> > owner;
int n, af, as, at, now;

int main()
{
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> af >> as >> at;
		persent[af][as] = at;
		par[af][as] = at;
		if (at > 50) 
		{
			mark[af][as] = true;
			owner.push_back( make_pair(af , as) ); 
		}
	}
	for (int i = 0; i < owner.size(); i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (mark[owner[i].first][j]) { continue; }
			if ( j != owner[i].first && persent[owner[i].first][j] <= 50) 
				persent[owner[i].first][j] += par[owner[i].second][j];
			if (persent[owner[i].first][j] > 50)
			{
				owner.push_back(make_pair(owner[i].first, j));
				mark[owner[i].first][j] = true;
			}
		}
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (i != j && persent[i][j] > 50) { cout << i << ' ' << j << endl; }
	return 0;
}