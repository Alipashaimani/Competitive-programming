#include <bits/stdc++.h>
using namespace std;

long long ans = 1, v = 0, cnt = 0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;    cin >> n >> k;

    if( k > n/2)
        k = n-k;

    for (int i = 0; i<n; i++){
        long long cnt2 = 2 * cnt + 1;
        v += k;
        if(v > n){
            v -= n;
            cnt2++;
            cnt++;
        }
        ans += cnt2;
        cout << ans <<" ";
    }
    return 0;
}