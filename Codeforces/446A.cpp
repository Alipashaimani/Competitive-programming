#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int dp[MAXN];
int arr[MAXN];
int dp2[MAXN];
int mx = 1 ;
int main(){
    int n;  cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];
    dp[0] = 1;  dp2[n-1] = 1;
    for (int i = 1 ; i < n ; i++){
        if (arr[i] > arr[i-1]){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = 1;

        }
        mx = max(mx, dp[i - 1] + 1);
    }

    for (int i = n-2 ; i >= 0 ; i--) {
        if (arr[i] < arr[i+1]) {
            dp2[i] = dp2[i+1] + 1;
        }
        else{
            dp2[i] = 1;
        }
        mx = max(mx, dp2[i + 1] + 1);
    }

    for (int i = 1 ; i < n-1 ; i++){
            if (arr[i+1] - arr[i-1] >= 2){
                mx = max(mx, dp[i-1] + dp2[i+1] + 1);
            }
    }
    cout << mx << endl;
}