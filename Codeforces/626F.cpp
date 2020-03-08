#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 210;
int arr[MAXN];
int dp[MAXN][MAXN][MAXN * 5];

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    dp[0][0][0]=1;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= m; k++){

                long long x = (k+j*(arr[i]-arr[i-1]));

                if(x > m)
                    continue;

                long long x2 = dp[i-1][j][k];
                dp[i][j][x] = (dp[i][j][x] + x2) % MOD;
                dp[i][j][x] = (dp[i][j][x] + ((long long)j * x2) % MOD) % MOD;
                dp[i][j + 1][x] = (dp[i][j + 1][x] + x2) % MOD;
                dp[i][j - 1][x] = (dp[i][j - 1][x] + ((long long)j * x2) % MOD) % MOD;
            }

    long long ans = 0;
    for (int i = 0 ;i <= m; i++)
        ans = (ans + dp[n][0][i]) % MOD;

    cout << ans << endl;
    return 0;
}