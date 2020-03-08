#include <bits/stdc++.h>
using namespace std;
int c[30100];
int main(){
    int a, b;
    cin >> a >> b;
    if ( a == b ) {
        cout<<"YES";
        return 0;
    }
    a-=1;
    for ( int i = 0 ; i < a ; i++ ) {
        cin >> c[i];
    }
    for ( int j = 0 ; j < a ;){
        if ( j == (b-1) ){
            cout<<"YES";
            return 0 ;
        }
        j += c[j];
    }
    cout<<"NO";
}