#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s ;
    cin >> s ;
    char c [100000] ;
    bool tt = true ;
    int p = 0, o = 0 ;
    for (int i = 0 ; i < s.size() ; i++)
    {
        tt = true ;
        for (int j = 0 ; j < s.size() ; j++)
        {
            if (s[i] == c[j])
                tt = false ;
        }

        if (tt)
        {
            c[o] = s[i] ;
            o++;
            p++;
        }
    }

    if (p % 2 == 1)
        cout << "IGNORE HIM!\n";
    else
        cout << "CHAT WITH HER!\n";

}