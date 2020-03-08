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

const int maxn=150;
int a[maxn][maxn];
ll s=0;

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            char c;
            cin>>c;
            a[i][j]=c-48;
            if(a[i][j]>0)
                s+=2;
        }
    }
    FOR(i, 1, n)
        FOR(j, 1, m)
            s+=max(0, a[i][j]-a[i-1][j])+max(0, a[i][j]-a[i][j+1])+max(0, a[i][j]-a[i][j-1])+max(0, a[i][j]-a[i+1][j]);
    cout<<s<<endl;
	return 0;
}
