#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int isprime(int a){
    if(a<=1)
        return false;
    for(int i=2; i*i<=a; i++)
        if(a%i==0)
            return false;
    return true;
}

int prsum(int a){
    bool found=false;
    ll sum=0;
    int i=1;
    for(i=1; i*i<a; i++){
        if(a%i==0){
            if(isprime(i))
                sum+=i;
            if(isprime(a/i))
                sum+=a/i;
        }
    }
    if(i*i==a && isprime(i))
        sum+=a;
    return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
    ll a, b;
    cin>>a>>b;
    ll fa=0, fb=0;
    for(ll i=1; i*i<=a; i++){
        if(a%i==0){
            if(isprime(a/i))
                fa=max(fa, a/i);
            else if(isprime(i))
                fa=max(fa, i);
        }
    }
    for(ll i=1; i*i<=b; i++){
        if(b%i==0){
            if(isprime(b/i))
                fb=max(fb, b/i);
            else if(isprime(i))
                fb=max(fb, i);
        }
    }
    while(a%fa==0)
        a/=fa;
    while(b%fb==0)
        b/=fb;
    fa-=prsum(a);
    fb-=prsum(b);
    if(fa>fb)
        cout<<"a\n";
    else
        cout<<"b\n";
	return 0;
}
