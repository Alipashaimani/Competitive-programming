/*
ID: apiv2002
PROG: hamming
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

vector <int> answersbaseten;
vector <string> answersbasetwo;
bool mark[8];
int num, length, dif, numnow;

void basetwototen(string s)
{
	int ans = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < length; i++)
	{
		if (s[i] == '1')
			ans += pow(2, i);
	}
	answersbaseten.push_back(ans);
}

void cmp(string s)
{
	for (int i = 0; i < answersbasetwo.size(); i++)
	{
		int ldif = 0;
		for (int j = 0; j < length; j++)
		{
			if (answersbasetwo[i][j] != s[j])
				ldif++;
		}
		if (ldif < dif)
			return;
	}
	numnow++;
	answersbasetwo.push_back(s);
	basetwototen(s);
}

bool tryall(int v)
{
	if (v == length)
	{
		if (numnow == num)
			return 1;
		string s = "";
		for (int i = 0; i < length; i++)
		{
			if (mark[i])
				s += '1';
			else
				s += '0';
		}
		cmp(s);
		return 0;
	}
	mark[v] = false;
	if (tryall(v + 1))
		return 1;
	mark[v] = true;
	if (tryall(v + 1))
		return 1;
	return 0;
}

int main()
{
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	cin >> num >> length >> dif;
	tryall(0);
	for (int i = 0; i < answersbaseten.size(); i++)
	{
		cout << answersbaseten[i];
		if (!((i + 1) % 10))
			cout << endl;
		else if (i == (answersbaseten.size() - 1))
			cout << endl;
		else
			cout << ' ';
	}
	cin >> num;
	return 0;
}