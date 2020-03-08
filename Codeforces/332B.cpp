#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 100;

ll n, k, a, b, c, ss, sum[MAXN];
ll psum(ll i) {return i+k-1 > n ? 0 : sum[i + k - 1] - sum[i - 1];}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x;  cin >> x;
        sum[i] = sum[i-1] + x;
    }
    ll mx = -1, mx2 = -1;
    for(int i = 1; i <= n; i++) {
        ss = psum(i);
        if(ss > mx) {
            mx = ss;
            c = i;
        }
        ss = psum(i + k);
        if(mx + ss > mx2) {
            mx2 = mx + ss;
            a = c;
            b = i + k;
        }
    }
    cout << a << " " << b << endl;
}