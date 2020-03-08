
#include <bits/stdc++.h>
using namespace std;
int main (){
    int a,b,c,j[6], maxn = 0;

    cin >> a >> b >> c ;
    j[0] = a + b + c ;
    j[1] = (a + b) * c ;
    j[2] = a + (b * c) ;
    j[3] = a * (b + c) ;
    j[4] = (a * b) + c ;
    j[5]=a*b*c;

    for ( int i = 0 ; i < 6 ; i++){
        maxn=max(maxn,j[i]);
    }
    cout<<maxn;
}