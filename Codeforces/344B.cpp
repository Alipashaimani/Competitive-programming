#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;
    if (  (a + b + c ) & 1 or a + b < c or a + c < b or b + c < a)
        return cout << "Impossible\n", 0;
    cout << ((a + b - c) >> 1)  << " " << ((b + c - a) >> 1) << " " << ((a + c - b) >> 1) << '\n';

}