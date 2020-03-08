//InTheNameOfGod
#include<bits/stdc++.h>
using namespace std;
int main(){
        char x1, y1, x2, y2;
        int a;
            cin >> x1 >> y1 >> x2 >> y2;
                a = max( abs ( x1 - x2 ), abs ( y1 - y2 ) );
                cout << a << '\n';
                for ( int i = 0 ; i < a ; i++ ) {
                    if ( x1 > x2 ){
                        cout<<'L';
                        x2++;
                    }
                    if ( x2 > x1 ){
                        cout<<'R';
                        x1++;
                    }
                    if ( y1 > y2 ) {
                        cout<<'D';
                        y2++;
                    }
                    if ( y2 > y1 ) {
                        cout<<'U';
                        y1++;
                    }
                    cout<<'\n';
                }

}