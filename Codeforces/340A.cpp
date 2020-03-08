#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, a, b; cin >> x >> y >> a >> b;
    int lcm = (x * y / __gcd(x, y));
    a--;
    cout << b / lcm - a / lcm << endl;
    return 0;
}