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
    int n;
    cin>>n;
    if(n<30){
        if(n==21)
            cout<<1<<endl;
        else
            cout<<-1<<endl;
        return 0;
    }
    if(n%14<=12 && n%14>1)
        cout<<n/14<<endl;
	else
        cout<<-1<<endl;
	return 0;
}
