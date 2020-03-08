#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long INF=100000000000LL;

vector<int> v[MAXN];
long long dp[MAXN], dp2[MAXN], arr[MAXN];

int main(){
    int n;  cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p >> arr[i];
        p--;

        if(p >= 0)
            v[p].push_back(i);
    }

    for(int i = n-1; i >= 0; i--){
        long long sum = 0, mn = INF, p = 0;

        for(int j = 0; j < v[i].size(); j++){
            int c = v[i][j];

            sum += max(dp[c], dp2[c]);

            if(dp[c] > dp2[c])
                p++;

            mn = min(mn, abs(dp2[c]-dp[c]));
        }
        dp[i] = sum + arr[i];
        dp2[i] = sum;
        if(p % 2 == 1){
            dp[i] -= min(mn, arr[i]);
            dp2[i] -= mn;
        }
    }

    cout << max(dp[0], dp2[0]) << endl;
}
