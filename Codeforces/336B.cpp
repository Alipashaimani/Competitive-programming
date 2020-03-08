#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
long double sq2 = sqrt(2), ans = 0;

int main(){
    ll m, r;    cin >> m >> r;

    if (m == 1)
        return cout << r * m * 2ll<< endl, 0;

    for (long long i = 2; i < m; i++){
        ans += 2 * (m - i - 1) * sq2 * r;
        ans += 2 * (i - 2) * sq2 * r;
        ans += (m - i - 1) * (m - i) * r;
        ans += (i - 2) * (i - 1) * r;
        ans += (sq2 * r + 2 * r) * 2;
    }

    ans += (sq2 * r + 2 * r) * 2;
    ans += 2 * (m - 2) * (m - 1) * r;
    ans += (m - 2) * sq2 * 2 * r * 2;
    ans += r * m * 2ll;
    ans /= m * m;
    return cout << fixed << setprecision(10) << ans << '\n' ,0;
}