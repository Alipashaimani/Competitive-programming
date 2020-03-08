#include <bits/stdc++.h>
using namespace std;
#define show(x) cerr << #x << " " << x << endl;
typedef long long ll;

const ll MAXN = (1 << 20);
const ll oo = 1100000000000000000;

ll dp[MAXN];
pair<ll,pair<ll,ll> > fri[100 + 30];

int main(){
    int n, m, b;
    cin >> n >> m >> b;
    for(int i = 0, que;i < n; i++){
        cin >> fri[i].second.first >> fri[i].first >> que;
        for (int j = 0, qnum; j < que ; j++){
            cin >> qnum;    qnum --;
            fri[i].second.second |= (1<<qnum);
        }
    }

    sort(fri, fri + n);
    fill(dp, dp + MAXN, oo);

    dp[0] = 0;
    ll ans = oo;
    for(int i = 0; i < n; i++){
        for(int j = (1 << m)-1; j>=0; j--)
            dp[j] = min(dp[j], dp[(j ^ fri[i].second.second) & j] + fri[i].second.first);
        ans = min(ans, dp[(1<<m)-1] + (fri[i].first * b) * 1LL);
    }
    show(ans);
    if( ans == oo)
        return cout << -1 << endl ,0 ;

    return cout << ans << endl ,0;
}