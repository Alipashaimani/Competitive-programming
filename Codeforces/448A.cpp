#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3], b[3], n, m = 0, suma = 0, sumb = 0;
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2] >> n ;
    suma = a[0] + a[1] + a[2] ;
    sumb = b[0] + b[1] + b[2] ;
    m = (suma / 5) + (sumb / 10 ) ;
    if ( suma % 5 >= 1 )
        m++;
    if ( sumb % 10 >= 1 )
        m++;
    cout << (( m <= n ) ? "YES" : "NO" );
}
