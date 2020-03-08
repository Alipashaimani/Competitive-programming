
#include <bits/stdc++.h>
using namespace std;
int main (){
    int a , b , j1=0 , j2=0 , j3=0 , m , n ;
    cin >> a >> b ;
    for ( int i = 1 ; 6>=i ; i++){
        m = abs ( a - i);
        n = abs ( b - i);
        if ( b == i )
            m=6;
        if ( m < n )
            j1++;

    }


    if  ((a + b) % 2 == 0){
        j2++;
    }

    j3= 6 - (j2 + j1 );

    if ( a == b ){
        j1 = 0 ; j2 = 6 ; j3 = 0 ;

    }
    cout<<j1<<" "<<j2<<" "<<j3;

}
