#include <bits/stdc++.h>
using namespace std ;

int main (){
    int n ;
    cin >> n ;
    string s,ss="" ;
    cin >> s ;

    for (int i = 0 ; i < n ; i++)
    {
        if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o')
        {
            int j ;
            for (j = i + 3 ; j < n ; j++)
            {
                if (s[j] == 'g' && s[j + 1] == 'o')
                    ++j ;
                else
                {
                    i = j - 1 ;
                    break ;
                }
            }
            ss += "***" ;
            i = j - 1 ;
        }
        else
            ss += s[i] ;
    }

    cout << ss;
}