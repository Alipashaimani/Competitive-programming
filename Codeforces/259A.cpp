#include <bits/stdc++.h>
#define B begin()
#define E end()
#define pp push_back
using namespace std;
int a=0,b=0;
int main() {
    string ss;
    for ( int i = 0 ; 8 > i ; i++){
        cin>>ss;
        a+=ss.find("WW")+ss.find("WWW")+ss.find("WWWW")+ss.find("WWWWW")+ss.find("WWWWWW")+ss.find("WWWWWWW")+ss.find("WWWWWWWW");
        b+=ss.find("BB")+ss.find("BBB")+ss.find("BBBB")+ss.find("BBBBB")+ss.find("BBBBBB")+ss.find("BBBBBBB")+ss.find("BBBBBBBB");
    }
    if (a==-56 && b==-56){
        cout<<"YES";

    }
    else {
        cout<<"NO";
    }

}