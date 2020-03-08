#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, Mishka = 0, Chris = 0, draw = 0;
    cin >> a;
    for ( int i = 0 ; i < a ; i++ ){
        int x, y;
        cin >> x >> y;
        if (x > y)
            Mishka ++;

        else if (x < y)
            Chris ++;

        else if ( x == y)
            draw ++;

    }

    if ( Mishka > Chris)
        cout << "Mishka";
    else if ( Chris > Mishka)
        cout << "Chris";
    else
        cout << "Friendship is magic!^^";
}