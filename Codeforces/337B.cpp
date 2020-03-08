#include <bits/stdc++.h>
using namespace std;
int ans1, ans2;
int main () {
    int a, b, c, d; cin >> a >> b >> c >> d;
    ans1 = abs((a * d) - (c * b));
    ans2 = max((a * d), (c * b)) ;
    cout << ans1/(__gcd(ans1, ans2)) << '/' << ans2/(__gcd(ans1, ans2)) << '\n';
    return 0;
}