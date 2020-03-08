#include <bits/stdc++.h>
using namespace std ;

long long a2 , a3, a5, a6, ans ;

int main (){
    cin >> a2 >> a3 >> a5 >> a6 ;

    while (a2 > 0 && a5 > 0 && a6 > 0){
        ans += 256 ;
        --a2 ;
        --a5 ;
        --a6 ;
    }

    while (a2 > 0 && a3 > 0){
        --a2 ;
        --a3 ;
        ans += 32 ;
    }

    cout << ans << endl ;

}