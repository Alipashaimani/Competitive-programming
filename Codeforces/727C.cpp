#include <bits/stdc++.h>
using namespace std;
int n,a[10000]={0},ans;
int main() {
    cin >> n;
    for (int i = 1; i < n ; i++) {
        cout << "? " << i << " " << n << '\n' << flush;
        cin >> a[i];
    }
    cout << "? 1 2\n" << flush;
    cin >> a[0];
    ans = (a[1] + a[2] - a[0]) / 2;
    cout << "! ";

    for (int i = 1; i < n; i++){
        cout << a[i]-ans << " ";
    }
    cout << ans <<" "<< flush;
}