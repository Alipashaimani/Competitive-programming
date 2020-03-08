#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, x , ans;

int main()
{
    cin >> n >> x;
    if (n == 2 && x == 0)
    {
        return cout << "NO" << endl, 0;
    }
    if (n == 2)
    {
        return cout << "YES\n" << 0 << ' ' << x << endl, 0;
    }
    if (n % 2 && x % 2)
    {
        cout << "YES" << endl;
        for (int i = 1; i < n; i++)
        {
            cout << 2 * i << ' ';
            ans ^= 2 * i;
        }
        cout << (ans ^ x) << endl;
        return 0;
    }
    if (n % 2 && x % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 1; i < n; i++)
        {
            cout << 2 * i - 1 << ' ';
            ans ^= 2 * i - 1;
        }
        cout << (ans ^ x) << endl;
        return 0;
    }
    if (n % 2 == 0 && x % 2)
    {
        cout << "YES" << endl;
        for (int i = 1; i < n; i++)
        {
            cout << 2 * i << ' ';
            ans ^= 2 * i;
        }
        cout << (ans ^ x) << endl;
        return 0;
    }
    if (n % 2 == 0 && x % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 1; i < n - 1; i++)
        {
            //cout << 2 * i << ' ';
            ans ^= 2 * i - 1;
        }
        if (ans == x)
        {
            ans = 0;
            cout << 0 << ' ';
            for (int i = 1; i < n - 2; i++)
            {
                cout << i * 2 - 1 << ' ';
                ans ^= i * 2 - 1;
            }
            ans ^= 2 * (n - 2) + 1;
            cout << 2 * (n - 2) + 1 << ' ' << (ans ^ x) << endl;
        }
        else
        {
            ans = 0;
            for (int i = 1; i < n - 1; i++)
            {
                cout << i * 2 - 1 << ' ';
                ans ^= i * 2 - 1;
            }
            cout << 0 << ' ' << (ans ^ x) << endl;
        }
        return 0;
    }
    return 0;
}