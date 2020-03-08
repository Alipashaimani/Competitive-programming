#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a, b, aa[5], bb[5], sum = 0 ;
    bool a2 = 0 , b2 = 0 ;
    cin >> a >> b;
    fill ( aa, aa + 5, (a / 5));
    fill ( bb, bb + 5, (b / 5));
    for ( int i = 4 ; i > 0 ; i--){
        if ( a % 5 == i || a2 == 1){
            aa[i]++;
            a2 = 1;
        }
        if ( b % 5 == i || b2 == 1){
            bb[i]++;
            b2 = 1;
        }
    }
    sum = (aa[0] * bb[0]) + (aa[1] * bb[4]) + (aa[2] * bb[3]) + (aa[3] * bb[2]) + (aa[4] * bb[1]);
    cout << sum << '\n' ;


}