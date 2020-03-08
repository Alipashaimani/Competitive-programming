#include<bits/stdc++.h>
using namespace std;
long long dp[31][31][51];

long long ans(int n,int m, int k){
    if (k == n * m || k == 0)
        return 0;
    if (~dp[n][m][k]){
        return dp[n][m][k];
    }

    long long cnt = 1e9;

    for (int i = 1 ; i < n ; i++){
        for (int j = 0 ; j < k ; j++){
            cnt = min(cnt, m*m + ans(i,m,j) + ans(n-i,m,k-j));
        }
    }

    for (int i = 1 ; i < m ; i++){
        for (int j = 0 ; j < k ; j++){
            cnt = min(cnt, n*n + ans(n,i,j) + ans(n,m-i,k-j));
        }
    }
    return dp[n][m][k] = cnt;
}
int main(){
    int t;  cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        int n,m,k;  cin >> n >> m >> k;
        cout << ans(n,m,k) << "\n";
    }
}
