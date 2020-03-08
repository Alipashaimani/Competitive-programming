#include <bits/stdc++.h>
using namespace std;

int a,b;

int main(){
    cin >> a >> b;
    if ( a == 1 && b == 1)
        return cout << 1 <<'\n',0;
    if (b > a/2)
        return cout << b-1 << endl,0;
    return cout << b+1 << endl,0;
}