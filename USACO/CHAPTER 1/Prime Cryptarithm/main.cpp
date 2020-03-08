/*
ID: apiv2002
PROG: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int transformer(string s)
{
	int a = 0;
	for (int i = 0; i < s.size(); i++)
	{
		a *= 10;
		a += (s[i] - 48);
	}
	return a;
}

bool checker(string s , int a , int d)
{
	bool accept = false;
	for (int i = 0; i < d; i++)
	{
		accept = false;
		if (a == 0)
			return 1;
		for (int j = 0; j < s.size(); j++)
		{
			if ((a % 10) == (s[j] - 48))
				accept = true;
		}
		if (!accept)
			return 0;
		a /= 10;
	}
	if (a)
		return 0;
	return 1;
}
int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w",stdout);
	int n, answer = 0;
	string sin;
	string soutA;
	string soutB;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char subsin;
		cin >> subsin;
		sin += subsin;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				for (int y = 0; y < n; y++)
				{
					for (int p = 0; p < n; p++)
					{
						soutA = "";
						soutB = "";
						soutA += sin[i];
						soutA += sin[j];
						soutA += sin[k];
						soutB += sin[y];
						soutB += sin[p];
						int intsoutA = transformer(soutA);
						int intsoutB = transformer(soutB);
						//cout << endl << intsoutA << "  " << intsoutB;
						int sum = intsoutA * (intsoutB % 10);
						if (!checker(sin, sum, 3))
							continue;
						//cout << 1;
						sum = intsoutA * (intsoutB / 10);
						if (!checker(sin, sum, 3))
							continue;
						//cout << 2;
						sum = intsoutA * intsoutB;
						if (!checker(sin, sum, 4))
							continue;
						//cout << 3;
						answer++;
					}
				}
			}
		}
	}
	cout << answer << '\n';
	//int uuu;
	//cin >> uuu;
	return 0;
}
