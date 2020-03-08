// 476 _ A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, ans;
    cin >> n >> m;
    ans = ((n + 2 * m - 1) / 2 / m * m);
    cout << ((m > n) ? -1 : ans ) << '\n';
}