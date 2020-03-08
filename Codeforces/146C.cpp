#include <bits/stdc++.h>
using namespace std;

int main (){
    string s, ss;
    cin >> s >> ss;
    int a = 0 ,b = 0;

    for ( int i = 0 ; i < s.size() ; i++){
        if ( s[i] != ss[i] && s[i] == '7') a ++;
        if ( s[i] != ss[i] && s[i] == '4') b ++;
    }
    cout << ( a>b ? a : b);

}