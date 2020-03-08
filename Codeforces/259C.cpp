#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int j=0;
    for ( int i = 0; s.size()>i;i++){
        if ( s[i]=='0'){
            j=i;
            break;
        }
    }
    for ( int i = 0 ; s.size()>i;i++){
        if ( i != j){
            cout<<s[i];
        }
    }

}