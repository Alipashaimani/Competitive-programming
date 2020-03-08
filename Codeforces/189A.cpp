// In the name of God
//code forces 189-A
#include <bits/stdc++.h>
using namespace std;
int dp[4001];
int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;

    dp[a] = 1;dp[b] = 1;dp[c] = 1;
    for(int i = 0; i <= n;i++){

        if(i >= a && dp[i-a] != 0 && dp[i-a]+1 > dp[i] )
                dp[i] = dp[i-a]+1;

        if(i >= b && dp[i-b] != 0 && dp[i-b]+1 > dp[i])
                dp[i] = dp[i-b]+1;


        if(i >= c && dp[i-c] != 0 &&  dp[i-c]+1 > dp[i])
                dp[i] = dp[i-c]+1;
    }

    cout << dp[n];
}