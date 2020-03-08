/*
ID: apiv2002
PROG: holstein
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int vitas[26];
int scoop[16][26];
bool mark[16];
bool markans[16];
int vitnum, scoopnum;
int minans = 1e8 , minnum = 1e2;

void cmp()
{
	int localanswer[26] = {};
	int localnum = 0;
	int localans = 0;
	for (int i = 0; i < scoopnum; i++)
	{
		if (mark[i])
		{
			localans += (i + 1);
			localnum++;
			for (int j = 0; j < vitnum; j++)
				localanswer[j] += scoop[i][j];
		}
	}
	for (int i = 0; i < vitnum; i++)
	{
		if (localanswer[i] < vitas[i])
			return;
	}
	if (localnum < minnum)
	{
		minnum = localnum;
		minans = localans;
		for (int i = 0; i < scoopnum; i++)
			markans[i] = mark[i];
		return;
	}
	if (localnum == minnum && localans < minans)
	{
		minnum = localnum;
		minans = localans;
		for (int i = 0; i < scoopnum; i++)
			markans[i] = mark[i];
		return;
	}
	return;
}

void tryall(int x)
{
	if (x == scoopnum)
	{
		cmp();
		return;
	}
	mark[x] = true;
	tryall(x + 1);
	mark[x] = false;
	tryall(x + 1);
	return;
}

int main()
{
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	cin >> vitnum;
	for (int i = 0; i < vitnum; i++)
		cin >> vitas[i];
	cin >> scoopnum;
	for (int i = 0; i < scoopnum; i++)
	{
		for (int j = 0; j < vitnum; j++)
			cin >> scoop[i][j];
	}
	tryall(0);
	cout << minnum;
	for (int i = 0; i < scoopnum; i++)
	{
		if (markans[i])
			cout << ' ' << (i + 1);
	}
	cout << endl;
	return 0;
}