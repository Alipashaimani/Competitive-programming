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

string a[1000 + 100];
int n;

bool check(int x){
    vector <int> s;
    rep(i, a[x].size())
        s.pb(a[x-1][i]+a[x-2][i]);
    for(int i=s.size(); i>0; i--){
        s[i-1]+=s[i]/10;
        s[i]%=10;
    }
    rep(i, s.size()){
        if(s[i]>a[x][i])
            return true;
        else if(s[i]<a[x][i])
            return false;
    }
    return false;
}

void print(int x){
    bool zero=false;
    rep(i, a[x-2].size()){
        if(a[x-2][i]>0)
            zero=true;
        if(zero)
            cout<<(int)a[x-2][i];
    }
    cout<<' ';
    zero=false;
    rep(i, a[x-1].size()){
        if(a[x-1][i]>0)
            zero=true;
        if(zero)
            cout<<(int)a[x-1][i];
    }
    cout<<' ';
    zero=false;
    rep(i, a[x].size()){
        if(a[x][i]>0)
            zero=true;
        if(zero)
            cout<<(int)a[x][i];
    }
    cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin>>n;
    rep(i, n){
        string s;
        cin>>s;
        rep(j, 510-s.size())
            a[i].pb(0);
        rep(j, s.size())
            a[i].pb(s[j]-48);
    }
    sort(a, a+n);
    FOR(i, 2, n-1){
        if(check(i)){
            print(i);
            return 0;
        }
    }
    cout<<"0 0 0"<<endl;

	return 0;
}
