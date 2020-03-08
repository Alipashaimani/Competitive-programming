/*
ID: apiv2002
PROG: preface
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int answers[7];
string numlet = "IVXLCDM";
string oet[] = { "" , "M" , "MM" , "MMM" };
string ont[] = { "" , "C" , "CC" , "CCC" , "CD" , "D" , "DC" , "DCC" , "DCCC" , "CM" };
string oeo[] = { "" , "X" , "XX" , "XXX" , "XL" , "L" , "LX" , "LXX" , "LXXX" , "XC" };
string oez[] = { "" , "I" , "II" , "III" , "IV" , "V" , "VI" , "VII" , "VIII" , "IX" };

void trans(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'I') { answers[0]++; }
		else if (input[i] == 'V') { answers[1]++; }
		else if (input[i] == 'X') { answers[2]++; }
		else if (input[i] == 'L') { answers[3]++; }
		else if (input[i] == 'C') { answers[4]++; }
		else if (input[i] == 'D') { answers[5]++; }
		else { answers[6]++; }
	}
	return;
}
void maker(int input)
{
	string output = "";
	if (input >= 1000)
	{
		output += oet[input / 1000];
		input %= 1000;
	}
	if (input >= 100)
	{
		output += ont[input / 100];
		input %= 100;
	}
	if (input >= 10)
	{
		output += oeo[input / 10];
		input %= 10;
	}
	if (input >= 1)
		output += oez[input];
	trans(output);
	return;
}

int main()
{
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		maker(i);
	for (int i = 0; i < 7; i++)
	{
		if (answers[i])
			cout << numlet[i] << ' ' << answers[i] << endl;
	}
	cin >> n;
	return 0;
}
