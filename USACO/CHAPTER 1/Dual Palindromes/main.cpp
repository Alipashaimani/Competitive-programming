/*
ID: apiv2002 
PROG: dualpal
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int baset;
string answer = "";
bool check()
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] != answer[answer.size() - i - 1])
			return 0;
	}
	return 1;
}

void trans()
{
	int nn = 0;
	for (int i = 0; ; i++)
	{
		nn = baset % n;
		if (nn > 9)
			answer += nn + 55;
		else
			answer += nn + 48;
		baset /= n;
		if (!baset)
			return;
	}
}

int main()
{
	int d, s, ans = 0, ansf = 0;
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	cin >> d >> s;
	for (int i = s + 1; ; i++)
	{
		baset = i;
		for (n = 2; n < 11; n++)
		{
			answer = "";
			baset = i;
			trans();
			if (check())
				ans++;
		}
		if (ans > 1)
		{
			cout << i << '\n';
			ansf++;
		}
		ans = 0;
		if (ansf == d)
			return 0;
	}
}
