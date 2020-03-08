#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN=70;
long long dp[MAXN], dig[MAXN];

long long sol(long long x){

    long long sz = 0, n = x, ans = 0;

    while(x){
        dig[++sz]=x % 2;
        x /= 2;
    }

    for (int i = 2; i <= sz; i++){

        memset(dp,0,sizeof(dp));

        for (int j = 1; j < i; j++){

            if (i%j)
                continue;

            if (i<sz)
                dp[j] = ( 1 << (j - 1));

            else{

                long long a = 0 ,b = 0;

                for (int k = 0; k < j; k++)
                    a += (dig[sz - k] << (j - 1 - k));

                b = a;
                for (int k = 1; k < sz/j; k++){
                    b<<=j;
                    b+=a;
                }
                dp[j] =  a - ( 1 << (j - 1) ) + 1 - (b > n);

            }
            for (int k = 1; k < j; k++)
                if(j % k == 0)
                    dp[j] -= dp[k];

            ans += dp[j];
        }
    }
    return ans;
}

int main(){
    long long x, y;  cin >> x >> y;
    return cout << sol(y)-sol(x-1) << '\n' ,0;
}
