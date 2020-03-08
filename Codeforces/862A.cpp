#include <bits/stdc++.h>

using namespace std;

set<int> s;
int n, x;

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		int y;
		cin >> y;
		s.insert(y);
	}
	int answer = x;
	for (auto i : s)
	{
		if (i < x)
		{
			answer--;
		}
		else if (i == x)
		{
			answer++;
		}
		else
		{
			break;
		}
	}
	cout << answer << endl;
	return 0;
}