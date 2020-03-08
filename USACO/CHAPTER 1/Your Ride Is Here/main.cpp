/*
ID:	apiv2002 
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int a[6];
int b[6];

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    string s;
    string h;
    cin >> s >> h;
    long long x = 1, v = 1;
    for (int i = 0; i < s.size(); i++)
        {
            a[i] = s[i] - 64;
            x = x * a[i];
        }
    for (int i = 0; i < h.size(); i++)
        {
            b[i] = h[i] - 64;
            v = v * b[i];
        }
    if (v % 47 == x % 47)
        cout << "GO" << "\n";
    else
        cout << "STAY" << "\n";



    return 0;
}
