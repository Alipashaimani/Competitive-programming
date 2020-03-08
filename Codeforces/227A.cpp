#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,d,e,f;  cin >> a >> b >> c >> d >> e >> f ;
    long long xa,xb,ya,yb;
    xa = c - a; xb = e - c;
    ya = d - b; yb = f - d;
    if ( (xa * yb - xb * ya ) > 0){
        cout << "LEFT";
    }
    else if ((xa * yb - xb * ya ) == 0){
        cout << "TOWARDS";
    }
    else{
        cout << "RIGHT";
    }
}