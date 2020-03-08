//462 - A
#include<bits/stdc++.h>
using namespace std;

char c[110][110];
int main(){
    int a, cnt = 0 ;
    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        for ( int j = 0 ; j < a ; j++){
            cin >> c[i][j];
        }
    }
    for ( int i = 0 ; i < a ; i++){
        for ( int j = 0 ; j < a ; j++){
                (c[i+1][j] == 'o' ? cnt ++ : cnt = cnt );
                (i-1 >= 0 && c[i-1][j] == 'o' ? cnt ++ : cnt = cnt );
                (c[i][j+1] == 'o' ? cnt ++ : cnt = cnt );
                ( j-1 >= 0 && c[i][j-1] == 'o' ? cnt ++ : cnt = cnt );
                if ( cnt % 2 == 1){
                    cout << "NO\n";
                    return 0;
                }
                cnt = 0;

            }
    }
    cout << "YES\n" ;
}
//489C
//313B