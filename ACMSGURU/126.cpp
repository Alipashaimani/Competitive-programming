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

ll a, b;
ll ans;

void F(){
    if(a>b)
        swap(a, b);
    if(a==0){
        cout<<ans<<endl;
        exit(0);
    }
    a*=2;
    b-=a/2;
    ans++;
    F();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>a>>b;
	if(a==0 or b==0){
        cout<<0<<endl;
        return 0;
	}
	ll t=__gcd(a, b);
	a/=t;
	b/=t;
	ll sum=a+b;
	if(__builtin_popcount(sum)!=1)
        cout<<-1<<endl;
    else
        F();
	return 0;
}
