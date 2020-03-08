#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int arr[MAXN], dp[MAXN][MAXN];

int main() {
    int n;   cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i <= n; i++)
        dp[i][i] = dp[i][i + 1] = 1;

    for (int l = 2; l <= n; l++)
        for (int i = 0; i + l <= n; i++) {
            dp[i][i + l] = dp[i + 1][i + l] + 1;
            for (int k = i + 1; k < i + l; k++)
                if (arr[k] == arr[i])
                    dp[i][i + l] = min(dp[i][i + l], dp[i + 1][k] + dp[k + 1][i + l] - (k == i + l - 1));
        }
    return cout << dp[0][n], 0;
}
