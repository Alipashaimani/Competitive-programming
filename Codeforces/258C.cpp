#include<bits/stdc++.h>
using namespace std;

const int  MAXN = 1e5 + 100  , MOD = 1e9 + 7 ;
int dp[MAXN] , n , mx;
long long ans , temp;
vector <int> divv;

long long power(long long x , long long y){
    if (y == 0)
        return 1;

    long long t = power (x, y / 2);
    t = (t * t) % MOD;
    if (y % 2 == 1)
        t = (t * x) % MOD;
    return t;
}

void dive(int x){
    divv.clear();
    for (int i = 1 ; i*i <=x ; i++){
        if (i * i == x)
            divv.push_back(i);
        else if (x % i == 0){
            divv.push_back(i);
            divv.push_back(x/i);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;  cin >> x;
        mx = max(x,mx);
        dp [x]++;
    }
    for (int i = 1; i < MAXN; i++)
        dp[i] = dp[i-1] + dp[i];

    for (int i = 1;  i <= mx; i++){
        dive(i);
        sort(divv.begin(),divv.end());
        temp = 1;
        for (int j = 1; j < divv.size(); j++){
            temp = (temp * power(j,dp[divv[j]-1] - dp[divv[j-1]-1])) % MOD;
        }
        long long a = ((temp * power(divv.size(),(dp[100000]-dp[divv[divv.size()-1]-1])) )%MOD);
        long long b = ((temp * power(divv.size() - 1,(dp[100000]-dp[divv[divv.size()-1]-1])) )%MOD);

        temp = a - b;
        if (temp <0)
            temp += MOD;

        ans = (ans +temp)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
