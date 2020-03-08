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
    string s, t;
    cin>>s>>t;
    vector <int> v, w;
    const int n=s.size();
    {
        int ct=0, cs=0;
        if(s.size()!=t.size()){
            cout<<-1<<endl;
            return 0;
        }
        rep(i, s.size())
            if(s[i]=='+'){
                cs++;
                w.pb(i);
            }
        rep(i, t.size())
            if(t[i]=='+'){
                ct++;
                v.pb(i);
            }
        if(ct!=cs){
            cout<<-1<<endl;
            return 0;
        }
    }
    int ans=0;
    rep(i, v.size())
        ans+=abs(v[i]-w[i]);
    cout<<ans<<endl;
	return 0;
}
