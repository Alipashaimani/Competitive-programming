#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100100;
ll arr[MAXN];
ll dp [MAXN];
ll dp2[MAXN];
ll n;
void F(){
    arr[n+1] = -1;
    
    for (ll i = n; i >= 1; i--){
        ll x = i+1;
        
        while(arr[x] >= arr[i])
            x=dp[x];
        
        dp[i] = x;
    }
    
    arr[0] = -1;
    for (ll i = 1 ; i <= n; i++){
        ll x = i-1;
        
        while(arr[x] >= arr[i])
            x=dp2[x];
        
        dp2[i] = x;
    }
}
int main(){
    while (cin >> n) {
        
        if (n == 0)
            return 0;
        
        for(ll i = 1 ; i <= n ; i++)
            cin >> arr[i];
        F();
        ll mx = 0;
        for (ll  i = 1; i <= n; ++i)
            mx = max(mx, (abs(dp[i] - dp2[i]) - 1) * arr[i]);
        
        cout << mx << '\n';
    }
}
