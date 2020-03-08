/*
ID: apiv2002
PROG: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int numofw;
int answer;
int ppo;

struct wormhole
{
	int X;
	int Y;
	int pairA;
	int pairB;
};

struct PPair
{
	int x;
	int y;
	int number;
};

wormhole input[13];
PPair s[12];

void loopfinder()
{
	for (int i = 1; i <= numofw; i++)
	{
		for (int j = i;;)
		{
			j = input[input[j].pairA].pairB;
			if (j == -1)
				break;
			if (j == i)
			{
				answer++;
				return;
			}
		}
	}
}

void TryThemAll(int vw)
{
	if (vw == numofw + 1)
	{
		loopfinder();
		return;
	}
	if (input[vw].pairA)
	{
		TryThemAll(vw + 1);
		return;
	}
	for (int i = vw + 1; i <= numofw; i++)
	{
		if (!input[i].pairA)
		{
			input[vw].pairA = i;
			input[i].pairA = vw;
			TryThemAll(vw + 1);
			input[i].pairA = 0;
		}
	}
	input[vw].pairA = 0;
	return;
}

bool cmp(PPair i, PPair j)
{
	if (i.y == j.y)
		return i.x < j.x;
	return i.y < j.y;
}

int main()
{
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	cin >> numofw;
	for (int i = 1; i <= numofw; i++)
	{
		cin >> input[i].X >> input[i].Y;
		s[i - 1].x = input[i].X;
		s[i - 1].y = input[i].Y;
		s[i - 1].number = i;
	}
	sort(s, s + numofw , cmp);
	for (int i = 0; i < numofw; i++)
	{
		if (i == numofw - 1)
		{
			input[s[i].number].pairB = -1;
			break;
		}
		if (s[i].y == s[i + 1].y)
		{
			input[s[i].number].pairB = s[i + 1].number;
		}
		else
			input[s[i].number].pairB = -1;
	}
	TryThemAll(1);
	cout << answer << '\n';
	return 0;
}
