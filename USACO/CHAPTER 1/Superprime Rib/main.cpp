/*
ID: apiv2002
PROG: sprime
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int en;
vector <int> answers;

bool prime(int num)
{
	int q = sqrt(num) + 1;
	for (int i = 2; i <= q && i != num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void dfs(int ed, int preans)
{
	if (ed > en)
	{
		answers.push_back(preans);
		return;
	}
	for (int i = 1; i < 10; i += 2)
	{
		if (prime((preans * 10) + i))
			dfs(ed + 1, (preans * 10) + i);
	}
	return;
}

int main()
{
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	cin >> en;
	for (int i = 2; i < 10; i++)
	{
		if (prime(i))
			dfs(2, i);
	}
	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;
	return 0;
}
