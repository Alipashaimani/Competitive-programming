//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a ,r=0;
    cin>>a;
    while (a>=5) {
        a-=5;
        r++;
    }
    while (a>=4) {
        a-=4;
        r++;
    }
    while (a>=3) {
        a-=3;
        r++;
    }
    while (a>=2) {
        a-=2;
        r++;
    }
    while (a>=1) {
        a-=1;
        r++;
    }
    cout<<r;


}
