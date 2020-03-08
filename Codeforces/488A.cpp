#include <bits/stdc++.h>
using namespace std;

bool lucky(long long a){
    a = abs(a);
    while (a){
        if (a % 10 == 8)
            return true;
        a /= 10;
    }
    return false;
}

int main() {
    long long n; cin >> n;
    long long newx = n+1;
    while (!lucky(newx))
        newx++;
    cout << newx - n;
}