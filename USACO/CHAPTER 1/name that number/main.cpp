/*
ID: apiv2002
PROG: namenum
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("namenum.in", "r",stdin);
    freopen("namenum.out", "w",stdout);
	string sA;
	string sB;
	char sC[14];
	bool yon;
	bool answer = false;
	cin >> sA;
    freopen("dict.txt", "r",stdin);
	for (int i = 0; ; i++)
	{
		cin >> sB;
		if (sB[0] == 'Z')
			break;
		if (sB.size() == sA.size())
		{
			for (int j = 0; j < sB.size(); j++)
			{
				if (sB[j] == 'Q' || sB[j] == 'Z')
					break;
				if (sB[j] == 'A' || sB[j] == 'B' || sB[j] == 'C')
					sC[j] = '2';
				if (sB[j] == 'D' || sB[j] == 'E' || sB[j] == 'F')
					sC[j] = '3';
				if (sB[j] == 'G' || sB[j] == 'H' || sB[j] == 'I')
					sC[j] = '4';
				if (sB[j] == 'J' || sB[j] == 'K' || sB[j] == 'L')
					sC[j] = '5';
				if (sB[j] == 'M' || sB[j] == 'N' || sB[j] == 'O')
					sC[j] = '6';
				if (sB[j] == 'P' || sB[j] == 'R' || sB[j] == 'S')
					sC[j] = '7';
				if (sB[j] == 'T' || sB[j] == 'U' || sB[j] == 'V')
					sC[j] = '8';
				if (sB[j] == 'W' || sB[j] == 'X' || sB[j] == 'Y')
					sC[j] = '9';
			}
			yon = true;
			for (int j = 0; j < sB.size(); j++)
			{
				if (sA[j] != sC[j])
					yon = false;
			}
			if (yon)
			{
				answer = true;
				cout << sB << '\n';
			}
		}
	}
	if (!answer)
	{
		cout << "NONE" << '\n';
	}
    return 0;
}
