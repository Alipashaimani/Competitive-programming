#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5  + 100;
ll n,k;
ll a[MAXN], b[MAXN];
bool check(ll mid){
    ll k2 = k;
    for ( int i = 0 ; i < n ; i++){
        if (mid * a[i]  > b[i]){
            if ( k2 - (-b[i]+(mid*a[i])) < 0){
                return 0;
            }
            k2 -= (-b[i]+(mid*a[i]));
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for ( int i = 0 ; i < n ; i++)
        cin >> a[i];

    for ( int i = 0 ; i < n ; i++)
        cin >> b[i];

    ll r = 2e9+100;
    ll l = 0;
    while (l+1<r) {
        ll mid = (l+r)/2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}