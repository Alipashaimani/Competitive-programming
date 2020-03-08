#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN  = 1e5 + 100;
const ll LMAXN = 3e9 + 100;
bool flag = 0;
ll a[MAXN],b[MAXN];
int main(){
    ll m,n;
    cin >> m >> n;
    for ( ll i = 0 ; i < m ; i++)
        cin >> a[i];
    for ( ll i = 0 ; i < n ; i++)
        cin >> b[i];
    sort(b,b+n);
    ll ans = 0;
    for ( ll i = 0 ; i < m ; i++){
        ll indexC = ll(upper_bound(b,b+n,a[i]) - b);
        ll f = abs(a[i] - b[indexC]);
        if ( indexC >= n)
            f = LMAXN;
        ans = max(ans , ( min(f,(indexC - 1 >= 0 ? abs (a[i]-b[indexC -1]) : f))));
    }
    cout << ans <<'\n';
}