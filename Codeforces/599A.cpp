//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int r1,r2,r3,r4,rr[4];
    r1=(a+b)*2;
    r2=a+b+c;
    r3=(a+c)*2;
    r4=(b+c)*2;
    rr[0]=r1;rr[1]=r2;rr[2]=r3;rr[3]=r4;
    sort(rr,rr+4);
    cout<<rr[0];
}