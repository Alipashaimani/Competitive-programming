#include <bits/stdc++.h>
using namespace std;
map<long long, long long> dp;

long long f(long long n){
    if(n == 0)
        return 0;
    
    if(dp[n]!=0)
        return dp[n];
    
    long long aux = f(n/2) + f(n/3) + f(n/4);
    
    dp[n] = max(aux,n);
    
    return dp[n];
}
long long a;
int main(){
    while(cin >> a){
        cout << f(a) << '\n';
    }
}
