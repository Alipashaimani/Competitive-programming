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

ll ans=0;
int n, m;
const int maxn=1e2;
int a[maxn][maxn];

void inc(int x, int y, int c)
{
    for(int i=0; i<n; i++)
        a[x+abs(i-y)][i]+=c;
    for(int i=x+1; i<n; i++)
        a[i][y]+=c;
}

void make(int k, int t){
    if(t>n-k)
        return;
    if(t==0 || k==n){
        ans++;
        return;
    }
    make(k+1, t);
    for(int i=0; i<n; i++){
        if(a[k][i]==0){
            inc(k, i, 1);
            make(k+1, t-1);
            inc(k, i, -1);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin>>n>>m;
    make(0, m);
    cout<<ans<<endl;
	return 0;
}
