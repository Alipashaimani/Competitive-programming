//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int r=0,m=0,a2;
    cin>>a2>>s;
    for ( int i = 0 ; s.size()>i ; i++){
        s[i]=tolower(s[i]);
    }
    for ( int i = 'a' ; 'z'>= i ; i++){
        r=s.find(i);
        if ( r >= 0 ){
            m++;
        }
    }
    cout<<(m==26?"YES":"NO");

}
