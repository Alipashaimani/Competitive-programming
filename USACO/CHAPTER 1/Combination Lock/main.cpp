/*
ID: apiv2002
PROG: combo
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	int n;
	int a[3];
	int b[3];
	cin >> n;
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	for (int i = 0; i < 3; i++)
		cin >> b[i];
	if (n < 6)
	{
		cout << (n * n * n) << '\n';
		return 0;
	}
	int answer = 250;
	int dif = 1;
	for (int i = 0; i < 3; i++)
	{
		int q = a[i] - b[i];
		int w = b[i] - a[i];
		if (q < 0)
			q += n;
		else
			w += n;

		if (q > 4)
			q = 5;
		if (w > 4)
			w = 5;
		dif *= (10 - (q + w));
	}
	answer -= dif;
	cout << answer << '\n';
	return 0;

}
