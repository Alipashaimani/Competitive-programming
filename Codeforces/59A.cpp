//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0,b=0;
    string s,ss,ss2;
    //97-122
    cin>>s;
    ss=s;ss2=s;
    for ( int i = 0 ; s.size()> i ; i++){
        ss[i]=toupper(ss[i]);
        ss2[i]=tolower(ss2[i]);
        if ( s[i]>=97 && s[i]<=122)
            a++;
        else
            b++;
    }
    if ( a >= b){
        cout<<ss2;
    }
    else {
        cout<<ss;
    }
}
