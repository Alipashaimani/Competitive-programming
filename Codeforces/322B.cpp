#include <bits/stdc++.h>
using namespace std;

int main(){
    long long r, g, b;    cin >> r >> g >> b;

    if(!( r && g && b ))
        return cout << r / 3 + b / 3 + g / 3 << endl, 0;

    if( (r-g) % 3 && (b-g) % 3 && (b-r) % 3)
        return cout << (r+g+b) / 3 - 1 << endl ,0;

    cout<< (r+g+b) / 3 <<endl;
}