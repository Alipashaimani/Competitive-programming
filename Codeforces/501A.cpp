#include <bits/stdc++.h>
using namespace std;

double a,b,c,d,misha,vaysa;

int main(){

    cin >> a >> b >> c >> d;

    misha = max((a * 3)/10,a - (c * a)/250);
    vaysa = max((b * 3)/10,b - (d * b)/250);

    if(misha > vaysa)
        return cout << "Misha" << endl,0;

    if(misha < vaysa)
        return cout << "Vasya" << endl,0;

    return cout << "Tie" << endl,0;
}