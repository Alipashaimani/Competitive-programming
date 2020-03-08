/*
ID: apiv2002
PROG: lamps
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

vector <int> onin;
vector <int> offin;
vector < pair<int, string> > answer;
bool mark[4];
int c, n;

bool cmp(pair<int, string> inputA , pair<int, string> inputB)
{
	return inputA.first < inputB.first;
}

int numbermaker(string s)
{
	int bio = 8;
	int ans = 0;
	for (int i = 0; i < 4 && i < n; i++)
	{
		if (s[i] - 48) ans += bio;
		bio /= 2;
	}
	return ans;
}
void checker()
{
	vector <bool> answers;
	int ons = 0;
	int ofs = 0;
	for (int i = 1; i <= n; i++)
	{
		bool cor = true;
		if (mark[0]) cor = !cor;
		if (mark[1] && i % 2) cor = !cor;
		if (mark[2] && !(i % 2)) cor = !cor;
		if (mark[3] && !((i - 1) % 3)) cor = !cor;
		if (ons < onin.size() && i == onin[ons])
		{
			ons++;
			if (!cor)
				return;
		}
		if (ofs < offin.size() && i == offin[ofs])
		{
			ofs++;
			if (cor)
				return;
		}
		answers.push_back(cor);
	}
	string ret = "";
	for (int i = 0; i < n; i++)
		ret += (48 + answers[i]);
	answer.push_back(make_pair(numbermaker(ret), ret));
	return;
}
void tryall(int x, int z)
{
	if (x == 4)
	{
		if (z <= c && !((c - z) % 2))
			checker();
		return;
	}
	mark[x] = true;
	tryall(x + 1 , z + 1);
	mark[x] = false;
	tryall(x + 1, z);
	return;
}

int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	cin >> n >> c;
	while (true)
	{
		int x;
		cin >> x;
		if (x == -1)
			break;
		onin.push_back(x);
	}
	while (true)
	{
		int x;
		cin >> x;
		if (x == -1)
			break;
		offin.push_back(x);
	}
	sort(onin.begin(), onin.end());
	sort(offin.begin(), offin.end());
	tryall(0, 0);
	if (!answer.size())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	sort(answer.begin(), answer.end(), cmp);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i].second << endl;
	return 0;
}
