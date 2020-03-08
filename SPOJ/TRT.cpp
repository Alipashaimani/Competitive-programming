#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 100;
int a[MAXN];
int dp[MAXN][MAXN];
int f (int i, int j, int age){
    if ( i > j )
        return 0;
    
    if ( dp[i][j])
        return dp[i][j];
    
    return dp[i][j] = max (a[j] * age + f ( i , j -1 , age + 1) , a[i] * age + f ( i  + 1 , j , age + 1));
    
}
int main(){
    int n;  cin >> n;
    for ( int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << f (0 , n , 0);
}
