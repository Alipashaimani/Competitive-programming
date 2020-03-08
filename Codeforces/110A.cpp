#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int a=0;
    cin>>s;
    for ( int i=0;s.size()>=i;i++){
        if(s[i]=='7' || s[i] == '4'){
            a++;
        }
    }
    if( (a == 7 || a == 4) && a>=1 ){cout<<"YES";}
    else
        cout<<"NO";



}