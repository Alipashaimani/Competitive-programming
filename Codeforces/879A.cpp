#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll now, n, s, t;
int main () {
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> s >> t;
        ll j = 0;
        for (; s + t * j <= now; ++j);
        now += abs(now - s - t * j);
    }
    return cout << now << '\n',0;
}