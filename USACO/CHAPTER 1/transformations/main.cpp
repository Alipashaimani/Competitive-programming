/*
ID: apiv2002
PROG: transform
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n;
bool a[11][11];
bool b[11][11];
bool c[11][11];
bool d[11][11];

bool answerf()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != d[i][j])
            return 0;
        }
    }
    return 1;
}

bool answerfB()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != c[i][j])
            return 0;
        }
    }
    return 1;
}

void Return()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = false;
        }
    }
}

int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
    char oio;
    cin >> n;
    for (int i = 0 ;i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> oio;
            if (oio == '@')
                b[i][j] = true;
        }
    }
    for (int i = 0 ;i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> oio;
            if (oio == '@')
                a[i][j] = true;
        }
    }
    int qa = 0;
    int qb = 0;
    for (int i = (n - 1); i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            d[j][i] = b[qa][qb];
			qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerf())
    {
        cout << 1 << '\n';
        return 0;
    }
    Return();
    qa = 0;
    qb = 0;
    for (int i = (n - 1); i >= 0; i--)
    {
        for (int j = (n - 1); j >= 0; j--)
        {
            d[i][j] = b[qa][qb];
			qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerf())
    {
        cout << 2 << '\n';
        return 0;
    }
    Return();
    qa = 0;
    qb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j >= 0; j--)
        {
            d[j][i] = b[qa][qb];
			qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerf())
    {
        cout << 3 << '\n';
        return 0;
    }
    Return();
    qa = 0;
    qb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j >= 0; j--)
        {
            c[i][j] = b[qa][qb];
            qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerfB())
    {
        cout << 4 << '\n';
        return 0;
    }
    ////  *4*  ////
    qa = 0;
    qb = 0;
    for (int i = (n - 1); i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            d[j][i] = c[qa][qb];
			qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerf())
    {
        cout << 5 << '\n';
        return 0;
    }
    Return();
    qa = 0;
    qb = 0;
    for (int i = (n - 1); i >= 0; i--)
    {
        for (int j = (n - 1); j >= 0; j--)
        {
            d[i][j] = c[qa][qb];
			qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerf())
    {
        cout << 5 << '\n';
        return 0;
    }
    Return();
    qa = 0;
    qb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j >= 0; j--)
        {
            d[j][i] = c[qa][qb];
			qb++;
        }
        qb = 0;
        qa++;
    }
    if(answerf())
    {
        cout << 5 << '\n';
        return 0;
    }
    Return();
    qa = 0;
    qb = 0;
    bool kj = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != d[i][j])
                kj = false;
        }
    }
    if (kj)
    {
        cout << 6 << '\n';
        return 0;
    }
    cout << 7 << '\n';
    return 0;
}
