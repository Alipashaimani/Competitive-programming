
#include <bits/stdc++.h>
using namespace std;
int main (){
    int m , n , j=0;
    cin >> n >> m ;
    for ( int a = 0 ; a * a <=  1000 ; a++ ){
        for ( int b = 0 ; b * b <= 1000 ; b++ ){
            if ( (a * a) + b == n && ( b * b ) + a == m   )
                j++ ;
        }
    }
    cout<< j;
}