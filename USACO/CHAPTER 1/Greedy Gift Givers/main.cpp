/*
ID: apiv2002
PROG: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

string s[10];
int a[10];
bool h[10];

int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int np, u = 0, vx, vc;
	string l;
	cin >> np;
	for (int i = 0; i < np; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < np; i++)
	{
		cin >> l;
		cin >> vx >> vc;
		if (vx == 0)
		{
			for (int j = 0; j < vc; j++)
				cin >> l;
			continue;
		}
			
		for (int j = 0; j < np; j++)
		{
			h[j] = false;
			if (s[j] == l)
			{
				u = j;
			}
		}
		for (int j = 0; j < vc; j++)
		{
			cin >> l;
			for (int k = 0; k < np; k++)
			{
				if (s[k] == l)
				{
					h[k] = true;
					break;
				}
			}
		}
		for (int j = 0; j < np; j++)
		{
			if (j == u)
			{
				a[j] -= vx;
				a[j] += vx % vc;
			}
			if (h[j])
			{
				a[j] += vx / vc;
			}
		}
	}
	for (int i = 0; i < np; i++)
	{
		cout << s[i] << " " << a[i] << "\n";
	}
	return 0;
}
