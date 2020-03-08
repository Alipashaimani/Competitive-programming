/*
ID: apiv2002
PROG: barn1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int a[220];

int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int answer = 0;
	int m, s, c;
	cin >> m >> s >> c;
	answer = s;
	for (int i = 0; i < c; i++)
	{
		cin >> a[i];
	}
	sort(a, a + c);
	answer -= a[0] - 1;
	answer -= s - a[c - 1];
	for (int i = c - 1; i > 0; i--)
	{
		a[i] -= (a[i - 1] + 1);
	}
	a[0] = -1;
	sort(a, a + c);
	for (int i = 0; i < m - 1 && i < c - 1; i++)
	{
		answer -= a[c - 1 - i];
	}
	cout << answer << '\n';
	return 0;
}
