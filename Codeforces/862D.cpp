#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n , kol;

void hal(int l, int r, int numofzero)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int mid = (l + r) / 2;
	cout << '?' << ' ';
	for (int i = 1; i < mid; i++)
	{
		cout << 1;
	}
	for (int i = mid; i < r; i++)
	{
		cout << 0;
	}
	for (int i = r; i <= n; i++)
	{
		cout << 1;
	}
	cout << endl;
	cin >> d;
	d -= kol;
	a = (numofzero + d - (r - mid)) / 2;
	c = d - a;
	b = (r - mid) - c;
	if (a == (mid - l) && c == (r - mid)) {
		cout << "! " << l << ' ' << mid << endl;
		exit(0);
	}
	if (a == 0 && c == 0) {
		cout << "! " << mid << ' ' << l << endl;
		exit(0);
	}
	if (a != 0 && a != (mid - l))
	{
		kol += b;
		hal(l, mid, a);
	}
	kol += a;
	hal(mid, r, b);
	return;
}

int main()
{
	cin >> n;
	cout << '?' << ' ';
	for (int i = 0; i < n; i++)
	{
		cout << 1;
	}
	cout << endl;
	int x;
	cin >> x;
	hal(1, n + 1, x);
	return 0;
}