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

int ans[300+50];

int main(){
	ios_base::sync_with_stdio(false);
    ll a, b, k;
    cin>>a>>b>>k;
    ans[0]=1;
    FOR(i, 1, k){
        FOR(j, 0, 300)
            ans[j]*=a+b;
        FOR(j, 0, 300){
            ans[j+1]+=ans[j]/10;
            ans[j]%=10;
        }
    }
    bool x=false;
    for(int i=300; i>=0; i--){
        if(ans[i]!=0)
            x=true;
        if(x)
            cout<<ans[i];
    }
    cout<<endl;
	return 0;
}
