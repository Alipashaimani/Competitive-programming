#include <bits/stdc++.h>
using namespace std;

const int  MAXN  = 3e4 + 100;
const int  MAXM =  600;

int n, l, dp[MAXN][MAXM], gem[MAXN], mx;
bool checl[MAXN][MAXM];

int dfs(int i, int j){
    if (i > mx || j == 0)
        return 0;

    if (checl[i][j])
        return dp[i][j];

    dp[i][j] = gem[i] + max(dfs(i + j - 1, j - 1), max(dfs(i + j, j) ,dfs(i + j + 1, j+ 1 )));

    checl[i][j] = true;
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;

    for(int i = 0; i < n;i++){
        int x;  cin >> x;

        mx = max(mx, x);
        gem[x]++;
    }
    return cout << dfs(l, l) << '\n', 0;
}