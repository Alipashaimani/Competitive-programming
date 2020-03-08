#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e15;
const int MAXN=2000+50;
ll dp[MAXN][MAXN*2],t[MAXN],c[MAXN];

int main(){
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> c[i];

    for(int i = 0;i < MAXN;i++)
        for(int j = 0 ;j < MAXN * 2; j++)
            dp[i][j] = inf;

    dp[0][MAXN]=0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < MAXN*2; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
            if(j-t[i-1] >= 0)
                dp[i][j]=min(dp[i][j], c[i-1]+dp[i-1][j-t[i-1]]);
        }
    ll ans = inf;
    for(int j = MAXN; j < MAXN * 2; j++)
        ans = min(ans, dp[n][j]);
    return cout << ans << endl, 0;
}
