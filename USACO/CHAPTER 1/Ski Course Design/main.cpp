/*
ID:	apiv2002 
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
int input[MAXN];

int main()
{
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	int number, answer = 99999999, maxhill = 0;
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cin >> input[i];
		if (input[i] > maxhill)
			maxhill = input[i];
	}
	for (int i = 0; i < 84; i++)
	{
		if ((i + 17) > maxhill)
			break;
		int localanswer = 0;
		for (int j = 0; j < number; j++)
		{
			if (input[j] < i)
				localanswer += ((i - input[j]) * (i - input[j]));
			else if (input[j] > i + 17)
				localanswer += ((input[j] - i - 17) * (input[j] - i - 17));
		}
		answer = min(answer, localanswer);
	}
	cout << answer << '\n';
	return 0;
}
