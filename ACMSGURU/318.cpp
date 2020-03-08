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

const int maxn = 100 + 50;
vector <int> v[maxn];
int n, m;
set <int> s;

int main(){
	ios_base::sync_with_stdio(false);
    cin>>n>>m;
    FOR(i, 1, m){
        int c;
        cin>>c;
        rep(j, c){
            int t;
            cin>>t;
            v[t].pb(i);
            s.insert(t);
        }
    }
    int ans=s.size();
    FOR(i, 1, n){
        FOR(j, i+1, n){
            if(v[i].size()!=0 && v[i]==v[j]){
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
