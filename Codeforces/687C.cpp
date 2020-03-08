#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
int c[MAXN], dp[MAXN], dp2[MAXN][MAXN];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> c[i];

    dp[0] = 1; dp2[0][0] = 1;

    for(int i = 0; i < n; ++i){
        for(int j = k - c[i]; j >= 0; --j){
            if(dp[j] == 1){
                dp[j + c[i]] = 1;
                for(int l = 0; l <= k; ++l){
                    if(dp2[j][l] == 1){
                        dp2[j + c[i]][l] = 1;
                        if(l + c[i] <= k)
                            dp2[j + c[i]][l + c[i]] = 1;
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= k; ++i)
        if(dp2[k][i]==1)
            ans++;

    cout << ans << endl;

    for(int i = 0; i <= k; ++i)
        if(dp2[k][i]==1)
            cout << i << " ";

    return 0;
}
