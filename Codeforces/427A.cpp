#include<bits/stdc++.h>
using namespace std;
int main(){
    int P = 0 , ans = 0 , n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i++){
        int x;
        cin >> x;

        if ( x == -1 && P == 0)
            ans ++ ;

        else if ( x == -1 && P > 0 )
            P -- ;

        else if ( x != -1 )
            P += x;

    }
    cout << ans;
}