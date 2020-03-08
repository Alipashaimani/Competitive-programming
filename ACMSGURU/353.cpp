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

int main(){
	ios_base::sync_with_stdio(false);
    ll n, p1, p2, p3, k1, k2, ans=0;
    cin>>n>>k1>>k2>>p1>>p2>>p3;
    if(n<p1){
        cout<<0<<endl;
        return 0;
    }
    n-=p1;
    ans+=k1;
    {
        int t=n/p2;
        if(t>k2){
            ans+=k2;
            n-=k2*p2;
        }
        else{
            cout<<ans+(n+p2-1)/p2<<endl;
            return 0;
        }
    }
    cout<<ans+(n+p3-1)/p3<<endl;
	return 0;
}
