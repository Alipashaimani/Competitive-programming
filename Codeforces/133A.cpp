#include<bits/stdc++.h>

using namespace std;
int main()
{
        string s ;
        cin >> s ;
        bool pp = 0 ;
        for (int i = 0 ; i < s.size() ; i++){

            if (s[i] == 'H' || s[i] =='Q' || s[i] == '9'){
                     cout<<"YES";
                    return 0;
                }
        }



        cout<<"NO";

}