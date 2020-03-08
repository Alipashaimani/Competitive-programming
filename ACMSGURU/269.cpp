#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 3e2, Ls = 6;
const ll L = 1e6;
vector <int> dp[maxn][maxn];
int b[maxn];
int n, k;

void DP(int i, int j){
    if(j == 0){
        dp[i][j].pb(1);
        return;
    }
    if(i == 0){
        dp[i][j].pb(0);
        return;
    }
    if(j > i || k - j > n - i || j > k){
        dp[i][j].pb(0);
        return;
    }

    //Update Other Cells
    if(dp[i - 1][j - 1].size() == 0)
        DP(i - 1, j - 1);
    if(dp[i - 1][j].size() == 0)
        DP(i - 1, j);
    //Update dp[i][j]
    dp[i][j] = dp[i - 1][j];
    ll t = b[i] - k + j;
    if(t > 0){
        int l = dp[i - 1][j - 1].size(), m = dp[i][j].size();
        if(m >= l){
            rep(ii, l)
                dp[i][j][ii] += dp[i - 1][j - 1][ii] * t;
        }
        else{
            rep(ii, m)
                dp[i][j][ii] += dp[i - 1][j - 1][ii] * t;
            rer(ii, m, l)
                dp[i][j].pb(dp[i - 1][j - 1][ii] * t);

        }
    }
    if(t > 0){
        int m = dp[i][j].size();
        rep(ii, m - 1){
            dp[i][j][ii + 1] += dp[i][j][ii] / L;
            dp[i][j][ii] %= L;
        }
        while(dp[i][j].back() >= L){
            dp[i][j].pb(dp[i][j].back() / L);
            dp[i][j][dp[i][j].size() - 2] %= L;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n >> k;
    reu(i, 1, n)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    DP(n, k);
    cout << dp[n][k].back();
    for(int i = dp[n][k].size() - 2; i >= 0; i--){
        ll t = dp[n][k][i];
        int c = 0;
        while(t > 0){
            c ++;
            t /= 10;
        }
        if(c == 0)
            c ++;
        rep(j, Ls - c)
            cout << 0;
        cout << dp[n][k][i];
    }
    cout << endl;
	return 0;
}



