/*
ID: apiv2002
PROG: friday
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int s[7];
int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
    int n , k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            s[k % 7]++;
			k += m[j];
            if (j == 1)
            {
                if ((1900 + i) % 4 == 0 && (1900 + i) % 100 != 0)
                    k++;
                if ((1900 + i) % 400 == 0)
                    k++;
            }
        }
    }
    for(int i = 0; i < 7; i++)
    {
        cout << s[i];
        if (i != 6)
            cout << " ";
    }
    cout << "\n";
	cin >> s[0];
    return 0;
}
