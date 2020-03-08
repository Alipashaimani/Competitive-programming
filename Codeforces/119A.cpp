#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,x,r=0;
    cin>>a>>b>>x;
    while (x!=0&&__gcd((r%2==0?a:b),x)<=x){
        x=x-(__gcd(x,(r%2==0?a:b)));
        r++;
    }
    if ( r % 2 == 0){
        cout<<"1";
    }
    else {
        cout<<"0";
    }
}