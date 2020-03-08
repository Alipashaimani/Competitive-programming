/*
ID: apiv2002
PROG: maze1
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

vector < pair<int, int> > vertex[220][90];
vector <string> input;
int distA[220][90];
int distB[220][90];
int h, w, maxy;
vector <pair <int, int> > pose;
bool markA[220][90];
bool markB[220][90];

void bfs(pair <int, int> pos, int(&dist)[220][90], bool (&mark)[220][90])
{
	queue < pair<int, int> > nexty;
	mark[pos.first][pos.second] = true;
	if (vertex[pos.first][pos.second].size())
	{
		mark[vertex[pos.first][pos.second][0].first][vertex[pos.first][pos.second][0].second] = true;
		dist[vertex[pos.first][pos.second][0].first][vertex[pos.first][pos.second][0].second] = 1;
		nexty.push(vertex[pos.first][pos.second][0]);
	}
	while (!nexty.empty())
	{
		for (int i = 0; i < vertex[nexty.front().first][nexty.front().second].size(); i++)
		{
			pair <int, int > g = nexty.front();
			if (!mark[vertex[g.first][g.second][i].first][vertex[g.first][g.second][i].second])
			{
				mark[vertex[g.first][g.second][i].first][vertex[g.first][g.second][i].second] = true;
				dist[vertex[g.first][g.second][i].first][vertex[g.first][g.second][i].second] = dist[g.first][g.second] + 1;
				nexty.push(vertex[g.first][g.second][i]);
			}
		}
		nexty.pop();
	}
}
int main()
{
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	cin >> w >> h;
	string s;
	getline(cin, s);
	for (int i = 0; i < (2 * h) + 1; i++)
	{
		input.push_back("");
		getline(cin , input[i]);
	}
	for (int i = 0; i < (2 * w) + 1; i++)
  {
    if (input[0][i] == ' ')
      {
        pose.push_back( make_pair(0 , i));
        vertex[0][i].push_back( make_pair(1 , i));
		vertex[1][i].push_back(make_pair(0, i));
      }
    if (input[2 * h][i] == ' ')
      {
        pose.push_back( make_pair(2 * h , i));
        vertex[2 * h][i].push_back( make_pair(2 * h - 1 , i));
		vertex[2 * h - 1][i].push_back(make_pair(2 * h, i));
      }
  }
  for (int i = 0; i < (2 * h) + 1; i++)
  {
    if (input[i][0] == ' ')
      {
        pose.push_back( make_pair(i , 0));
        vertex[i][0].push_back( make_pair(i , 1));
		vertex[i][1].push_back(make_pair(i, 0));
      }
    if (input[i][2 * w] == ' ')
      {
        pose.push_back( make_pair(i , 2 * w));
        vertex[i][2 * w].push_back( make_pair(i , 2 * w - 1));
		vertex[i][2 * w - 1].push_back(make_pair(i, 2 * w));
      }
  }
  for (int i = 1; i < 2 * h; i += 2)
  {
    for (int j = 1; j < 2 * w; j+= 2)
    {
      if (i - 2 >= 0 && input[i - 1][j] == ' ') {vertex[i][j].push_back( make_pair(i - 2, j));}
      if (i + 2 <= 2 * h && input[i + 1][j] == ' ') {vertex[i][j].push_back( make_pair(i + 2, j));}
      if (j - 2 >= 0 && input[i][j - 1] == ' ') {vertex[i][j].push_back( make_pair(i, j - 2));}
      if (j + 2 <= 2 * w && input[i][j + 1] == ' ') {vertex[i][j].push_back( make_pair(i, j + 2));}
    }
  }
  bfs(pose[0], distA, markA);
  bfs(pose[1], distB, markB);
  for (int i = 1; i < 2 * h; i++)
  {
	  for (int j = 1; j < 2 * w; j++)
	  {
		  if (markA[i][j] && markB[i][j])
		  {
			  if (min(distA[i][j], distB[i][j]) > maxy)
				  maxy = min(distA[i][j], distB[i][j]);
		  }
		  else if (markA[i][j])
		  {
			  if (distA[i][j] > maxy)
				  maxy = distA[i][j];
		  }
		  else if (markB[i][j])
		  {
			  if (distB[i][j] > maxy)
				  maxy = distB[i][j];
		  }
    }
  }
  cout << maxy << endl;
  return 0;
}
