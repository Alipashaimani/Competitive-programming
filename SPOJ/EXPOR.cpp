#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100007;
#define ll long long
ll t, n;
ll arr[MAXN];
ll ache[MAXN];

int main(){
    scanf("%llu",&t);
    while (t--) {
        memset(ache, 0LLU, sizeof(ache));
        scanf("%llu",&n);
        for ( int i = 0 ; i < n ; i++){
            scanf("%llu",arr+i);
            for ( int j = 0 ; j <= 31 ; j++){
                if (arr[i]&(1LL<<j))
                    ache[j]++;
            }
        }
        ll num = 0, dnum ;
        for ( ll i = 0 ; i <= 31 ; i++){
            num+=((ache[i]*(n-ache[i])))*(1LL<<i);
            num+=((ache[i]*(ache[i]-1))/2)*(1LL<<i);
        }
        dnum = ((n*(n-1))>>1LL);
        
        ll gcd = __gcd(num,dnum);
        num/=gcd;
        dnum/=gcd;
        printf("%llu/%llu\n",num,dnum);
    }
    return 0;
}
