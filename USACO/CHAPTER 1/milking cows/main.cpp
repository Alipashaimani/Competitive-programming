/*
ID: apiv2002
PROG: milk2
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int a[5000];
int b[5000];

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int mxA = 0 , pmx = 0 , premx = 0 , mxB = 0 , z = 2;
    int n;
    cin >> n;
    for (int i = 0; i <  n; i++)
    {
        cin >> a[i] >> b[i];
    }
    while (z--)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] >= a[j] && a[i] <=  b[j] && b[i] <= b[j])
                {
                    a[i] = -1;
                    b[i] = -1;
                    break;
                }
                else if (a[i] >= a[j] && a[i] <=  b[j] && b[i] > b[j])
                {
                    a[i] = -1;
                    b[j] = b[i];
                    b[i] = -1;
                    break;
                }
                else if (a[i] < a[j] && b[i] >= a[j] && b[i] <= b[j] )
                {
                    a[j] = a[i];
                    a[i] = -1;
                    b[i] = -1;
                    break;
                }
            }
        }
    sort(a,a+n);
    sort(b,b+n);
    }
    for (int i = 0; i < n; i++)
    {
        pmx = b[i] - a[i];
        if (pmx > mxA)
            mxA = pmx;
    }
    for (int i = 0; i < n; i++)
    {
       if (b[i] != -1)
       {
           premx = b[i];
           for (int j = i + 1 ; j < n ; j++)
           {
               if ((a[j] - premx) > mxB)
                    mxB = a[j] - premx;
                premx = b[j];
           }
           break;
       }
    }
    cout << mxA << " " << mxB << endl;
    return 0;
}
