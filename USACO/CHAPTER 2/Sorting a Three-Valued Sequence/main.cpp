/*
ID: apiv2002
PROG: sort3
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
int notcor[3][3];
int numof[3];
int nin, answers;
vector <int> input;
int main()
{
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	cin >> nin;
	for (int i = 0; i < nin; i++)
	{
		int s;
		cin >> s;
		input.push_back(s);
		if (s == 1)
			numof[0]++;
		if (s == 2)
			numof[1]++;
		if (s == 3)
			numof[2]++;
	}
	for (int i = 0; i < nin; i++)
	{
		if (i < numof[0])
		{
			if (input[i] == 2)
				notcor[0][1]++;
			if (input[i] == 3)
				notcor[0][2]++;
		}
		else if (i < numof[0] + numof[1])
		{
			if (input[i] == 1)
				notcor[1][0]++;
			if (input[i] == 3)
				notcor[1][2]++;
		}
		else
		{
			if (input[i] == 2)
				notcor[2][1]++;
			if (input[i] == 1)
				notcor[2][0]++;
		}
	}
	int s = min(notcor[0][1], notcor[1][0]);
	answers += s;
	notcor[0][1] -= s;
	notcor[1][0] -= s;
	numof[0] = max(notcor[0][1], notcor[1][0]);
	s = min(notcor[0][2], notcor[2][0]);
	answers += s;
	notcor[0][2] -= s;
	notcor[2][0] -= s;
	numof[1] = max(notcor[0][2], notcor[2][0]);
	s = min(notcor[2][1], notcor[1][2]);
	answers += s;
	notcor[2][1] -= s;
	notcor[1][2] -= s;
	numof[2] = max(notcor[2][1], notcor[1][2]);
	s = min(numof[0], numof[1]);
	s = min(s, numof[2]);
	answers += s;
	s = max(numof[0], numof[1]);
	s = max(s, numof[2]);
	answers += s;
	cout << answers << endl;
	cin >> nin;
	return 0;
}