//InTheNameOfGod
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1 , y1 , x2 , y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
         int deltaX  = abs ( x1 - x2 );
         int deltaY = abs ( y1 - y2 );
        if ( x1 == y1 && x2 == y2 || deltaX == deltaY ){
            cout<<x1<< " " << y2 << " " << x2 << " " << y1;
        }
        else if ( x1 == x2 ) {
            cout<< x1 + deltaY << " " << y1 << " " << x2 + deltaY << " " << y2 ;
        }

        else if ( y1 == y2 ){
            cout << x1 << " " << y1 + deltaX << " " << x2 << " " << y2 + deltaX ;
        }

        else
            cout << -1;

}
