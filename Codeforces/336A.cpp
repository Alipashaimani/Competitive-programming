#include<bits/stdc++.h>
using namespace std;

int x, x2, y, y2;

int main(){
    int a ,b;  cin >> a >> b;

    if((a < 0 && b > 0) || (a > 0 && b < 0)){
        x = 0 ;
        y = -a + b;
        x2 = a + -b;
        y2 = 0;
    }
    else{
        x = 0 ;
        y = a + b;
        x2 = a + b;
        y2 = 0;
    }

    if(x > x2){
        swap(x,x2);
        swap(y,y2);
    }

    return cout << x << " " << y << " " << x2 << " "<< y2 << '\n', 0;
}