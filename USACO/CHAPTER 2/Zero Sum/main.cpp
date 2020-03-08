/*
ID: apiv2002
PROG: zerosum
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

string s = "000000000";
int n;

void compare()
{
	vector <int> answers;
	answers.push_back(1);
	for (int i = 0; i < (n - 1); i++)
	{
		if (s[i] == ' ')
		{
			answers[answers.size() - 1] *= 10;
			answers[answers.size() - 1] += i + 2;
			continue;
		}
		answers.push_back(i + 2);
	}
	int ans = answers[0];
	int cnt = 0;
	for (int i = 0; i < (n - 1); i++)
	{
		if (s[i] == ' ') { continue; }
		if (s[i] == '-') { ans -= answers[++cnt]; }
		else { ans += answers[++cnt]; }
	}
	if (!ans)
	{
		cout << 1;
		for (int i = 0; i < (n - 1); i++)
		{
			cout << s[i] << i + 2;
		}
		cout << endl;
	}
	return;
}
void tryall(int q)
{
	if (q > n)
	{
		compare();
		return;
	}
	if (q == n)
	{
		tryall(q + 1);
		return;
	}
	s[q - 1] = ' ';
	tryall(q + 1);
	s[q - 1] = '+';
	tryall(q + 1);
	s[q - 1] = '-';
	tryall(q + 1);
	return;
}

int main()
{
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	cin >> n;
	tryall(1);
	return 0;
}
