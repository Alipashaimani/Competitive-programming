// In the name of God
//code forces 266-B
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    string s;
    cin>>a>>b>>s;
    for ( int i = 0 ; b > i ; i++){
        for ( int j = 0 ; a > j ; j++){
            if ( s[j]=='B'&& s[j+1]=='G'){
                swap ( s[j],s[j+1]);
                j++;
            }
        }
    }
    cout<<s;
}