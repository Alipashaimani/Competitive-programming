#include <bits/stdc++.h>
using namespace std ;

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2 ; i++) {
        cout << i << " " << n - i + 1 << " ";
    }
    if (n % 2)
        cout << n / 2 + 1;

    return 0;
}