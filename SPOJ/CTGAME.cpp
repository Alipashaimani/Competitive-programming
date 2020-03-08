#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100100;
ll arr[MAXN],dp [MAXN],dp2[MAXN];
ll n,m;
ll histogram(ll a[]){
    a[n+1] = -1;
    
    for (ll i = n; i >= 1; i--){
        ll x = i+1;
        
        while(a[x] >= a[i])
            x=dp[x];
        
        dp[i] = x;
    }
    
    a[0] = -1;
    for (ll i = 1 ; i <= n; i++){
        ll x = i-1;
        
        while(a[x] >= a[i])
            x=dp2[x];
        
        dp2[i] = x;
    }
    ll mx = 0;
    for (ll  i = 1; i <= n; ++i)
        mx = max(mx, (abs(dp[i] - dp2[i]) - 1) * a[i]);
    return mx;
}

int main(){
    int t;  cin >> t;
    while(t--){
        cin >> m >> n;
        ll mx2 = 0;
        for (int i = 0 ; i < m ; i++){
            for (int j = 1 ; j <= n ; j++){
                char x; cin >> x;
                if (i == 0)
                    arr[j] = (x == 'F' ? 1 : 0);
                else
                    arr[j] = (x == 'F' ? arr[j]+1 : 0);
            }
            mx2 =  max(histogram(arr),mx2);
        }
        cout << mx2*3 << endl;
    }
}
