#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int flag = 0 , last = 0 ;

    for ( int i = 0; i < s.size() ; i++)
        if ( s[i]!= '/'){
            last = i;
        }

    cerr << last;

    for ( int i = 0 ; i < s.size() ; i++ ) {
        if ( s[i] == '/' )
            flag++ ;
        else
            flag = 0 ;

        if ( flag <= 1 && i <= last )
            cout << s[i];

    }

}
