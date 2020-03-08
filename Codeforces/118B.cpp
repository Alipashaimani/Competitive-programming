#include<bits/stdc++.h>
using namespace std;
int main () {
    int n,a,b;
    cin >> n;
    for (int j = 0; j <= 2 * n; ++j) {
        a = n - abs(j - n);
        b = 0;
        while (b < n - a) {
            cout << "  " ;
            ++b;
        }
        b = a;
        while(b > -a){
            cout << a - abs(b) << " ";
            --b;
        }
        cout << 0 << '\n';
    }
    return 0;
}