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

bool mark[100+50];

int main(){
	ios_base::sync_with_stdio(false);
    int n, f;
    cin>>n>>f;
    int a[n];
    rep(i, n){
        cin>>a[i];
        mark[a[i]]=true;
    }
    rep(i, n){
        if(f<a[i]){
            while(f<=a[i]){
                if(mark[f]){
                    cout<<f<<' ';
                    mark[f]=false;
                }
                f++;
            }
            f--;
        }
        else if(f>a[i]){
            while(f>=a[i]){
                if(mark[f]){
                    cout<<f<<' ';
                    mark[f]=false;
                }
                f--;
            }
            f++;
        }
        else{
            if(mark[f]){
                cout<<f<<' ';
                mark[f]=true;
            }
        }
    }
	return 0;
}
