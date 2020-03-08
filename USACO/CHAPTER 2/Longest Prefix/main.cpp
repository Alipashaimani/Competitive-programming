/*
ID: apiv2002
PROG: prefix
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

string input;
vector <string> primitive;
bool mark[200002];

int main()
{
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	string s;
	while (cin >> s)
	{
		if (s[0] == '.') break;
		primitive.push_back(s);
	}
	while (cin >> s) input += s;
	for (int i = 0; i < input.size(); i++)
	{
		if (i != 0 && !mark[i - 1]) continue;
		for (int j = 0; j < primitive.size(); j++)
		{
			if ((i + primitive[j].size() - 1) < input.size() && input.substr(i, primitive[j].size()) == primitive[j])
				mark[i + primitive[j].size() - 1] = true;
		}
	}
	for (int i = input.size() - 1; i >= -1; i--)
	{
		if (i == -1 || mark[i])
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
}
