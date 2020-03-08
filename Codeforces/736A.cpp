#include <iostream>
using namespace std;
const int MAXN = 105;
long long dp[MAXN], n,ans;
int main(){
    cin >> n;

    dp[0] = 1; dp[1] = 2;

    for (int i = 2; i < MAXN; i++)
        dp[i] = dp[i - 2] + dp[i - 1];


    while (dp[ans + 1] <= n)
        ans++;

    return cout << ans << '\n' , 0;

}