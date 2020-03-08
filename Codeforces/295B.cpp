#include <bits/stdc++.h>
using namespace std;
const int MAXN  = 500;
long long dp[MAXN][MAXN];
long long n;
long long ans[MAXN];
bool mark[MAXN];
vector<int>q;

void sum(int x, int u){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (mark[i] && mark[j])
                ans[u] += dp[i][j];
        }
}

void floyd_warshall(int x){
    mark[x] = true;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){

            dp[i][j]= min (dp[i][j],dp[i][x] + dp[x][j]);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> dp[i][j];
        }
    }

    for (int i = 0 ; i < n ; i++){
        int x;  cin >> x;
        q.push_back(x);
    }
   for (int k = n - 1; k >= 0; k--) {
       int x = q[k] - 1;
        floyd_warshall(x);
        sum(x,k);
    }
    for (int i = 0 ; i < n ; i++)
        cout << ans[i] << " ";
}