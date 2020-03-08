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
    int n, m;
    cin>>n>>m;
    int scr[n];
    memset(scr, 0, sizeof scr);
    rep(i, m){
        int a, b;
        cin>>a>>b;
        rep(j, n){
            int fi, se;
            cin>>fi>>se;
            if(fi-se==a-b)
                scr[j]+=3;
            if(a>b && fi>se)
                scr[j]+=2;
            if(a<b && fi<se)
                scr[j]+=2;
            if(a==b && fi==se)
                scr[j]+=2;
            if(a==fi)
                scr[j]++;
            if(b==se)
                scr[j]++;
        }
    }
    rep(i, n)
        cout<<scr[i]<<' ';
	return 0;
}
