/*
ID: apiv2002
PROG: frac1
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool mark[161][161];
int num;
vector < pair<int, int> > answers;

void marker(int a, int b)
{
	for (int i = 1; (a * i) <= num && (b * i) <= num; i++)
		mark[a * i][b * i] = true;
}

bool cmp(pair <int, int> fe, pair <int, int> se)
{
	return ((long double)fe.first / (long double)fe.second) < ((long double)se.first / (long double)se.second);
}

int main()
{
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	cin >> num;
	cout << "0/1" << endl;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (!mark[i][j])
			{
				marker(i, j);
				answers.push_back(make_pair(j, i));
			}
		}
	}
	sort(answers.begin(), answers.end(), cmp);
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i].first << '/' << answers[i].second << endl;
	cin >> num;
	return 0;
}