/*
ID: apiv2002 
PROG: palsquare
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int baset;
string answer = "";
string answerB = "";
bool check()
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] != answer[answer.size() - i - 1])
			return 0;
	}
	return 1;
}

void trans()
{
	int nn = 0;
	for (int i = 0; ; i++)
	{
		nn = baset % n;
		if (nn > 9)
			answer += nn + 55;
		else
			answer += nn + 48;
		baset /= n;
		if (!baset)
			return;
	}
}

int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < 301; i++)
	{
		baset = (i * i);
		trans();
		if (check())
		{
			int z = i;
			int qq = 0;
			for (int k = 0; ; k++)
			{
				qq = z % n;
				if (qq > 9)
					answerB += qq + 55;
				else
					answerB += qq + 48;
				z /= n;
				if (!z)
					break;
			}
			reverse(answer.begin(), answer.end());
			reverse(answerB.begin(), answerB.end());
			cout << answerB << " " << answer << '\n';
		}
		answer = "";
		answerB = "";
	}
	return 0;
}
