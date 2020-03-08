#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 1;
    for (int i = 1; i < n; i++) {
        x += i;
        if (x > n){
            x %= n;
        }
        cout << x << " ";
    }
    return 0;
}