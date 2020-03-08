#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x;
ll minN = 1e9 + 100, maxN = 0;
ll cntn, cntm;
ll ans;
vector<ll>a;
int main(){
    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> x;
        minN = min(minN, x);
        maxN = max(maxN, x);
        a.push_back(x);
    }
    cout << maxN - minN ;
    for(ll i = 0 ; i < n ; i++){
        if (a[i] == minN)
            cntn++;
        else if (a[i] == maxN)
            cntm++;
    }
    ans = (cntm==0 ? 1ll*n*(n-1)/2 : 1ll*cntm * cntn);
    cout << " " << ans << '\n';
}