#include<bits/stdc++.h>
using namespace std;
int a0=0,a1=0;
int main(){
    int n;
    string s;
    cin>>n>>s;
    for ( int i = 0 ;s.size()>i;++i ){
        if ( s[i]=='0'){
            a0++;
        }
        else if ( s[i]=='1'){
            a1++;
        }
    }
    cout<<abs(a1-a0);
}