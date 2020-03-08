/*
ID: apiv2002
PROG: beads
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int s[355];
int p[355];

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    bool q = true;
	int h = 0, hmx = 0, ans = 1, mx = 0, z = 0, ppp = 0, qqq = 0, yyy = 0;
    int n;
    char w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
		if (w == 'r')
		{
			p[i] = 1;
			qqq++;
		}
		else if (w == 'b')
		{
			p[i] = 2;
			yyy++;
		}
		else
		{
			p[i] = 3;
			ppp++;
		}
    }
	if (ppp == n || qqq == n || yyy == n)
	{
		cout << n << "\n";
		return 0;
	}
    for(int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
			s[j] = p[j];
		}
		if (s[i] == 3)
            continue;
        for (int j = i; ; j++)
        {
			if (j + 1 == n)
			{
				if (s[0] == 3)
					s[0] = s[n - 1];
				if (s[0] == s[n - 1])
				{
					ans++;
					if (ans == n)
					{
						mx = ans;
						break;
					}
				}
				else
				{
					if (q)
					{
						q = false;
						ans++;
						if (ans == n)
						{
							mx = ans;
							break;
						}
					}
					else
					{
						q = true;
						if (mx < ans)
						{
							mx = ans;
						}
						ans = 1;
						break;
					}
				}
			}
            else if (j + 1 > n)
            {
					if (s[j + 1 - n] == 3)
						s[j + 1 - n] = s[j - n];
                if (s[j + 1 - n] == s[j - n])
                {
                    ans++;
					if (ans == n)
					{
						mx = ans;
						break;
					}
                }
                else
                {
                    if (q)
                    {
                        q = false;
                        ans++;
						if (ans == n)
						{
							mx = ans;
							break;
						}
                    }
                    else
                    {
                        q = true;
                        if (mx < ans)
                        {
                            mx = ans;
                        }
                        ans = 1;
                        break;
                    }
               }
            }
			else
			{
				if (s[j + 1] == 3)
					s[j + 1] = s[j];
				if (s[j + 1] == s[j])
                {
					ans++;
					if (ans == n)
					{
						mx = ans;
						break;
					}
                }
                else
                {
                    if (q)
                    {
                        q = false;
                        ans++;
						if (ans == n)
						{
							mx = ans;
							break;
						}
                    }
                    else
                    {
                        q = true;
                        if (mx < ans)
                        {
                            mx = ans;
                        }
                        ans = 1;
                        break;
                    }
               } 
            }
        }
     }
    for(int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
			s[j] = p[j];
		}
		if (s[i] != 3)
            continue;
        for (int j = i; ; j++)
        {
			if (j + 1 == n)
			{
				if (s[0] == 3)
					s[0] = s[n - 1];
				if (s[0] == s[n - 1])
				{
					ans++;
					if (ans == n)
					{
						mx = ans;
						break;
					}
				}
				else
				{
					if (z < 2)
					{
						z++;
						ans++;
						if (ans >= n)
						{
							mx = n;
							break;
						}
					}
					else
					{
						z = 0;
						if (ans >= n)
							ans = n;
						if (mx < ans)
						{
							mx = ans;
						}
						ans = 1;
						break;
					}
				}
			}
            else if (j + 1 > n)
            {
					if (s[j + 1 - n] == 3)
						s[j + 1 - n] = s[j - n];
                if (s[j + 1 - n] == s[j - n])
                {
                    ans++;
					if (ans >= n)
					{
						mx = n;
						break;
					}
                }
                else
                {
                    if (z < 2)
                    {
                        z++;
                        ans++;
						if (ans >= n)
						{
							mx = n;
							break;
						}
                    }
                    else
                    {
                        z = 0;
                        if (ans >= n)
                            ans = n;
                        if (mx < ans)
                        {
                            mx = ans;
                        }
                        ans = 1;
                        break;
                    }
               }
            }
			else
			{
				if (s[j + 1] == 3)
					s[j + 1] = s[j];
				if (s[j + 1] == s[j])
                {
                    ans++;
					if (ans >= n)
					{
						mx = n;
						break;
					}
                }
                else
                {
                    if (z < 2)
                    {
                        z++;
                        ans++;
						if (ans >= n)
						{
							mx = n;
							break;
						}
                    }
                    else
                    {
                        z = 0;
                        if (ans >= n)
                        ans = n;
                        if (mx < ans)
                        {
                            mx = ans;
                        }
                        ans = 1;
                        break;
                    }
               } 
            }
        }
     } 
     cout << mx << "\n";
	 //int uu;
	 //cin >> uu;
     return 0;
}
