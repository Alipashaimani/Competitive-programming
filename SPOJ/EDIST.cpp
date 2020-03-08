#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAXN = 2e3 + 10;
int l,m,dp[MAXN][MAXN];
string s,g;
int change(int i, int j){
    if (i >= l)
        return m-j;
    
    if (j >= m)
        return l-i;
    
    if (dp[i][j]!= -1)
        return dp[i][j];
    
    if ( s[i] == g[j])
        dp[i][j] = change(i+1,j+1);
    else
        dp[i][j] = min (1+change(i+1,j+1) , min ( 1 + change(i+1, j) ,1 + change(i, j+1) ));
    
    return dp[i][j];
}
int main(){
    int t;  cin >> t;
    while (t--) {
        memset(dp,-1,sizeof(dp));
        cin >> s >> g;
        l = int(s.size());
        m = int(g.size());
        cout << change(0,0) << '\n';
    }
}


