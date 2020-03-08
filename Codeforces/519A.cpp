// 519 _ A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int sumW = 0 , sumB = 0 ;
    for ( int i = 0; i < 64 ; i++){
        char c;
        cin >> c;
        sumW +=(c == 'Q' ? 9 : 0 );
        sumW +=(c == 'R' ? 5 : 0 );
        sumW +=(c == 'B' ? 3 : 0 );
        sumW +=(c == 'N' ? 3 : 0 );
        sumW +=(c == 'P' ? 1 : 0 );

        sumB +=(c == 'q' ? 9 : 0 );
        sumB +=(c == 'r' ? 5 : 0 );
        sumB +=(c == 'b' ? 3 : 0 );
        sumB +=(c == 'n' ? 3 : 0 );
        sumB +=(c == 'p' ? 1 : 0 );
    }
    cout << ( sumW == sumB ? "Draw\n" : ( sumW > sumB) ? "White\n" : "Black\n");
}