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

const int maxn=1e2+50;
int f, v;
ll a[maxn][maxn];
ll dp[maxn][maxn];
vector <int> ans;
bool par[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
    cin>>f>>v;
    FOR(i, 1, f)
        FOR(j, 1, v)
            cin>>a[i][j];
    FOR(i, 1, f){
        dp[i][i]=dp[i-1][i-1]+a[i][i];
        par[i][i]=true;
        FOR(j, i+1, v){
            dp[i][j]=dp[i-1][j-1]+a[i][j];
            par[i][j]=true;
            if(dp[i][j-1]>dp[i][j]){
                dp[i][j]=dp[i][j-1];
                par[i][j]=false;
            }
        }
    }
    int root=v;
    int sen=f;
    while(sen>0){
        if(par[sen][root]){
            ans.pb(root);
            sen--;
        }
        root--;
    }
    cout<<dp[f][v]<<endl;
    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<' ';
    cout<<endl;
	return 0;
}
