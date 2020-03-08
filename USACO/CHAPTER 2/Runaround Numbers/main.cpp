/*
ID: apiv2002
PROG: runround
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool uni(string s)
{
	sort(s.begin(), s.end());
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1]) return 1;
	}
	return 0;
}
bool checker(int input)
{
	int len = 0 ,z = 0 ,n = input;
	bool mark[] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	string s;
	while (n)
	{
		if (!(n % 10))
			return 1;
		s += (n % 10);
		n /= 10;
	}
	reverse(s.begin(), s.end());
	if (uni(s)) return 1;
	while(true)
	{
		if (mark[z])
			return 1;
		mark[z] = true;
		z += s[z];
		z %= s.size();
		len++;
		if (len == s.size() && !z)
			return 0;
	}
}

int main()
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	unsigned int n;
	cin >> n;
	n++;
	while (checker(n)) n++;
	cout << n << endl;
	return 0;
}
