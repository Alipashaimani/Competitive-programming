#include <bits/stdc++.h>
using namespace std;
int main (){
    int m=0,j1=0,j2=0,l=0;
    string s;
    cin>>m;
    cin>>s;
    m-=1;
    for ( int i = 0; m>i*2 ; i++){
        j1+=s[i];
        j2+=s[m-i];
    }
    for ( int i = 0 ; s.size()>i ; i++ ) {
        if ( s[i] == '4' || s[i] == '7'){
            l++;
        }

    }
    if ( l != s.size() )
        j1=0;

        cout<<( j1==j2 ? "YES" : "NO");
    return 0;
}