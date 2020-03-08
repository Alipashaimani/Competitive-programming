#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
long long m,n,a[MAXN];
long long ans = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0 ; i < m ; i++)
        cin >> a[i];

    for ( int i = 0 ; i < m ; i++){
        long long cnt = upper_bound(a,a+m,a[i]+n) - a;
        ans += ((cnt - i - 1) * (cnt - i - 2)) / 2;
        cerr << ans << " " << cnt << '\n';
    }
    return cout << ans << '\n' ,0;
}