#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     pb              push_back
#define     mp              make_pair
#define     p1              first
#define     p2              second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int k;
int num[200];

void zarb(int a){
    rep(i, 200)
        num[i]*=a;
    rep(i, 199){
        num[i+1]+=num[i]/10;
        num[i]%=10;
    }
}

void tagh(int a){
    int t=0;
    for(int i=199; i>=0; i--){
        t*=10;
        t+=num[i];
        num[i]=t/a;
        t%=a;
    }
}

void solve(){
    FOR(i, k+1, 2*k){
        zarb(i);
        tagh(i-k);
    }
    tagh(k+1);
}

int main()
{_
    cin>>k;
    num[0]=1;
    solve();
    bool hel=false;
    for(int i=199; i>=0; i--){
        if(num[i]!=0)
            hel=true;
        if(hel)
            cout<<num[i];
    }
    cout<<' '<<k+1<<endl;
    return 0;
}
