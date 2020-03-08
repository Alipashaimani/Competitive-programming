#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main(){
    cin >> a >> b;
    while(a % b){
        c += a / b;
        a %= b;
        a ^= b;     b ^= a;     a ^= b;
    }
    c += a / b;
    return cout << c << '\n' , 0;
}
