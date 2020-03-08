#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
const ll MAXN = 1e6 + 100;
ll a[MAXN] , n , m , ans=0 ;
map <ll, ll > mil ;
int main (){
    cin >> n >> m ;
    for (int i = 1; i <= n; i++){
        cin >> a[i] ;
        ans += mil[m^a[i]];
        mil[a[i]]++;
    }
    cout << ans ;
}
