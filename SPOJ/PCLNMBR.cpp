#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll a,b,c;
ll gcd(ll a, ll b){if (a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll fun (ll n){
    ll temp = lcm(a,b);
    ll ans = n/a - n/temp;
    ans += n/lcm(temp,c);
    return ans;
}
ll solve(ll p){
    ll lo  = 0 , hi = 1e18;
    ll ans = 0 , mid ;
    while(lo<= hi){
        mid = (lo+hi)/2;
        ll val = fun(mid);
        if ( val < p){
            lo=mid+1;
        }
        else if ( val >= p ){
            hi = mid-1;
            ans = mid;
        }
    }
    return ans;
}
int main(){
    int q;
    ll p;
    scanf("%lld%lld%lld%d",&a,&b,&c,&q);
    for (int i = 1 ; i <= q ; i++){
        scanf("%lld",&p);
        printf("%lld\n",solve(p));
    }
}

