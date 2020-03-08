#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    string b;
    cin >> a >> b;

    if ( a == 3)
        cout<<b;

    else if ( a % 2 != 0 && a >= 4 ){

        cout << b[0] << b[1] << b[2] << '-' ;

        for ( int i = 3 ; i < a; i++){
            cout << b[i] ;

            if ( i % 2 == 0 && (i + 1) != a)
                cout << '-' ;
        }
        return 0;
    }

    else {

        for ( int i = 0 ; i < a ; i++){
            cout << b[i] ;

            if ( i % 2 == 1 && (i + 1) != a)
                cout << '-' ;
        }
    }

    return 0;
}
