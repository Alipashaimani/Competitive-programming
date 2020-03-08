/*
ID: apiv2002
PROG: ariprog
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

bool subs[124510];
int n , m;

void builtall()
{
  for (int i = 0; i <= m; i++)
  {
    for (int j = i; j <= m; j++)
    {
      subs[(i * i) + (j * j)] = true;
	  //cout << "DEBUG 1 : " << (i * i) + (j * j) << endl;
    }
  }
}

vector <pair<int,int> > answers;

bool cmp(pair <int, int> A, pair <int, int> B)
{
	if (A.second == B.second)
		return A.first < B.first;
	return A.second < B.second;
}
int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	cin >> n >> m;
	builtall();
	for (int i = 0; i < 2 * (m * m); i++)
	{
		if (subs[i])
		{
			for (int j = i + 1;((j - i) * (n - 1) + i) <= 2 * (m * m); j++)
			{
				if (subs[j])
				{
					bool yon = true;
					for (int k = 2; k < n; k++)
					{
						//cout << i << " " << j << " " << k  << " " << i + (k * (j - i)) << endl;
						//cout << i + (k * (j - i)) << endl;
						if (!subs[i + (k * (j - i))])
						{
							yon = false;
							//cout << "n" << endl;
							k = n;
						}
					}
					if (yon)
					{
						answers.push_back(make_pair(i, j - i));
					}
				}
			}
		}
	}
	if (answers.size() == 0)
	{
		cout << "NONE" << endl;
		//cin >> n;
		return 0;
	}
	sort(answers.begin(), answers.end(), cmp);
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i].first << ' ' << answers[i].second << endl;
	cin >> n;
	return 0;
}
