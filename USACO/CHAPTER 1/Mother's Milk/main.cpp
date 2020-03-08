/*
ID: apiv2002
PROG: milk3
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
bool mark[21][21][21];
bool flag[21];
int inputA, inputB, inputC;

void dfs(int a, int b, int c)
{
	if (mark[a][b][c])
		return;
	mark[a][b][c] = true;
	if (a == 0 && !flag[c])
	{
		flag[c] = true;
	}
	if (a + b <= inputB)
		dfs(0, a + b, c);
	else
		dfs(a + b - inputB, inputB, c);
	if (c + b <= inputB)
		dfs(a, c + b, 0);
	else
		dfs(a, inputB, c + b - inputB);
	if (a + b <= inputA)
		dfs(a + b, 0, c);
	else
		dfs(inputA , a + b - inputA, c);
	if (a + c <= inputA)
		dfs(a + c,b, 0);
	else
		dfs(inputA, b, a + c - inputA);
	if (a + c <= inputC)
		dfs(0, b,a + c);
	else
		dfs(a + c - inputC, b, inputC);
	if (b + c <= inputC)
		dfs(a , 0,b + c);
	else
		dfs(a, b + c - inputC, inputC);
	return;
}

int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	cin >> inputA >> inputB >> inputC;
	dfs(0, 0, inputC);
	bool answer = true;
	for (int i = 0; i < 21; i++)
	{
		if (answer && flag[i])
		{
			answer = false;
			cout << i;
			continue;
		}
		if (flag[i])
			cout <<' ' << i;
	}
	cout << endl;
	return 0;
}
