/*
ID: apiv2002
PROG: ttwo
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

char input[10][10];
int ans ;
pair <int, int> posF, posC;
enum direction {UP , RIGHT , DOWN , LEFT };
direction Fdir = UP, Cdir = UP;

void goF()
{
	int x = 0, y = 0;
	if (Fdir == UP) { x = 1; }
	if (Fdir == RIGHT) { y = 1; }
	if (Fdir == DOWN) { x = -1; }
	if (Fdir == LEFT) { y = -1; }
	if ((posF.first + x) < 10 && (posF.second + y) < 10)
	{
		if ((posF.first + x) >= 0 && (posF.second + y) >= 0)
		{
			if (input[posF.first + x][posF.second + y] != '*')
			{
				posF.first += x;
				posF.second += y;
				return;
			}
		}
	}
	if (Fdir == UP) 
	{
		Fdir = RIGHT;
		return;
	}
	if (Fdir == RIGHT) 
	{ 
		Fdir = DOWN;
		return;
	}
	if (Fdir == DOWN)
	{ 
		Fdir = LEFT;
		return;
	}
	if (Fdir == LEFT) 
	{
		Fdir = UP;
		return;
	}
}

void goC()
{
	int x = 0, y = 0;
	if (Cdir == UP) { x = 1; }
	if (Cdir == RIGHT) { y = 1; }
	if (Cdir == DOWN) { x = -1; }
	if (Cdir == LEFT) { y = -1; }
	if ((posC.first + x) < 10 && (posC.second + y) < 10)
	{
		if ((posC.first + x) >= 0 && (posC.second + y) >= 0)
		{
			if (input[posC.first + x][posC.second + y] != '*')
			{
				posC.first += x;
				posC.second += y;
				return;
			}
		}
	}
	if (Cdir == UP)
	{
		Cdir = RIGHT;
		return;
	}
	if (Cdir == RIGHT)
	{
		Cdir = DOWN;
		return;
	}
	if (Cdir == DOWN)
	{
		Cdir = LEFT;
		return;
	}
	if (Cdir == LEFT)
	{
		Cdir = UP;
		return;
	}
}

int main()
{
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> input[i][j];
			if (input[i][j] == 'F')
			{
				posF.first = i;
				posF.second = j;
			}
			if (input[i][j] == 'C')
			{
				posC.first = i;
				posC.second = j;
			}
		}
	}
	for (ans; ans < 1e6; ans++)
	{
		if (posF.first == posC.first && posF.second == posC.second)
		{
			cout << ans << endl;
			return 0;
		}
		goF();
		goC();
	}
	cout << 0 << endl;
	return 0;
}