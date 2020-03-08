/*
ID: apiv2002
PROG: milk
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

struct farmer
{
    int price = 0;
    int amount = 0;
};

bool cmp(farmer i, farmer j)
{
	if (i.price == j.price)
		return i.amount < j.amount;
	return i.price < j.price;
}

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
    int n , m;
    long long answer = 0;
    cin >> n >> m;
    farmer s[5 * 1000];
    for (int i = 0; i < m ; i++)
    {
        cin >> s[i].price >> s[i].amount;
    }
	sort(s, s + m, cmp);
    for (int i = 0; ;i++)
    {
        if (n < s[i].amount)
        {
            answer += n * s[i].price;
            break;
        }
        else
        {
			n -= s[i].amount;
            answer += s[i].price * s[i].amount;
        }
    }
    cout << answer << '\n';
    return 0;
}
