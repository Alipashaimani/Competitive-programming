#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n , m , q;
long long a, arrb[MAXN], psum[MAXN];
long long rr[MAXN];

long long query()
{
	int index = lower_bound(rr + 1, rr + m - n + 2, -a) - rr - 1;
	long long answer = 1e18;
	if (index >= 1 && index <= m - n + 1)
	{
		answer = min(answer, abs(a + rr[index]));
	}
	if (index > 1 && index <= m - n + 2)
	{
		answer = min(answer, abs(a + rr[index - 1]));
	}
	if (index >= 0 && index < m - n + 1)
	{
		answer = min(answer, abs(a + rr[index + 1]));
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a += (i & 1 ? 1 : -1) * x;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> arrb[i];
	}
	for (int i = m; i; i--)
	{
		psum[i] = psum[i + 1] * -1 + -1 * arrb[i];
		if (i <= m - n + 1)
		{
			rr[i] = psum[i] - ((n & 1 ? -1 : 1) * psum[i + n]);
		}
	}
	sort(rr + 1, rr + m - n + 2);
	cout << query() << endl;
	while (q--)
	{
		long long l, r, ans;
		cin >> l >> r >> ans;
		a += (l & 1 ? 1 : -1) * ((r - l + 1) % 2) * ans;
		cout << query() << endl;
	}
	return 0;
}