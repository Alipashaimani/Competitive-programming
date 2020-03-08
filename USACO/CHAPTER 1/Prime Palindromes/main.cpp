/*
ID: apiv2002 
PROG: pprime
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

vector <int> answers;

bool prime(int num)
{
	int q = sqrt(num) + 1;
	for (int i = 2; i <= q; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	int st, en;
	cin >> st >> en;
	// 1 & 2
	for (int i = 1; i < 10; i += 2)
	{
		int ans = (i * 10) + i;
		if (i >= st && i <= en && prime(i))
			answers.push_back(i);
		if (ans >= st && ans <= en && prime(ans))
			answers.push_back(ans);
	}
	// 3 & 4
	for (int j = 1; j < 10; j += 2)
	{
		for (int i = 0; i < 10; i++)
		{
			int ans = (j * 100) + (i * 10) + j;
			if (ans >= st && ans <= en && prime(ans))
				answers.push_back(ans);
			ans = (j * 1000) + (i * 100) + (i * 10) + j;
			if (ans >= st && ans <= en && prime(ans))
				answers.push_back(ans);
		}
	}
	// 5 & 6
	for (int i = 1; i < 10; i += 2)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				int ans = (i * 10000) + (j * 1000) + (k * 100) + (j * 10) + (i);
				if (ans >= st && ans <= en && prime(ans))
					answers.push_back(ans);
				ans = (i * 100000) + (j * 10000) + (k * 1000) + (k * 100) + (j * 10) + (i);
				if (ans >= st && ans <= en && prime(ans))
					answers.push_back(ans);
			}
		}
	}
	// 7 * 8
	for (int i = 1; i < 10; i += 2)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				for (int z = 0; z < 10; z++)
				{
					int ans = (i * 1000000) + (j * 100000) + (k * 10000) + (z * 1000) + (k * 100) +(j * 10) + (i);
					if (ans >= st && ans <= en && prime(ans))
						answers.push_back(ans);
					ans = (i * 10000000) + (j * 1000000) + (k * 100000) + (z * 10000) + (z * 1000) + (k * 100) + (j * 10) + (i);
					if (ans >= st && ans <= en && prime(ans))
						answers.push_back(ans);
				}
			}
		}
	}
	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;
	return 0;
}
