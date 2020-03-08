#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0,b=1;
    string s;
    cin>>s;
    for ( int i = 0 ; s.length()>i;i++){
        a=0;
        if ( s[i]=='0'|| s[i]=='2'||s[i]=='6'||s[i]=='9'){a+=2;}
        else if ( s[i]=='1'){a+=7;}
        else if ( s[i]=='3' || s[i]=='4'){a+=3;}
        else if ( s[i]=='5'){a+=4;}
        else if ( s[i]=='7'){a+=5;}
        else if ( s[i]=='8'){a++;}
        b*=a;
        }
    cout<<b;
    }
