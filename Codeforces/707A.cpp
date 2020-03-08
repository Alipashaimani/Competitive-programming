#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    char c;
    cin >> a >> b;
    for ( int i = 0 ; i < a ; i++){
        for ( int j = 0 ; j < b ; j++){
            cin >> c;
            if ( c == 'C' || c == 'M' || c == 'Y'  ){
                cout << "#Color";
                return 0;
            }
        }
    }
    cout << "#Black&White";
}