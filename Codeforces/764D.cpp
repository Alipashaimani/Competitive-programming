#include <bits/stdc++.h>
using namespace std;
int n, a, b, x;
int main(){
    cout << "YES\n";
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> x >> x;
        cout << 1 + 2 * (abs(a) % 2) + (abs(b) % 2) << '\n';
    }
    return 0;
}