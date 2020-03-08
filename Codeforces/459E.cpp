#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
int n,m ;
const int MAXN = 300001;
pair<int , pair<int , int>> edge[MAXN];
int dp[MAXN];
int dp2[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m ;
    for (int i = 0 ; i < m ; i++){
        int x,y,z;
        cin >> x >> y >> z;
        edge[i] = {z , {x , y}};
    }
    int idx = 0, ans = 0;
    sort(edge, edge + m);
    reverse(edge, edge + m);

    for (int i = 0; i < m; i++) {
        if (i && edge[i-1].first != edge[i].first){
            for (;idx < i;idx++)
                dp2[edge[idx].S.F] = max(dp2[edge[idx].S.F], dp[idx]);
        }

        dp[i] = max(1, dp2[edge[i].S.S] + 1);
        ans = max(ans , dp[i]);
    }
    cout << ans << endl;
    return 0;
}