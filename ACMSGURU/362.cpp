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

bool a[15][15];

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    int ii, jj;
    cin>>ii>>jj;
    FOR(i, 1, n)
        FOR(j, 1, m)
            a[i][j]=true;
    while(1){
        a[ii][jj]=false;
        if(a[ii+1][jj]){
            cout<<'D';
            ii++;
        }
        else if(a[ii][jj-1]){
            cout<<'L';
            jj--;
        }
        else if(a[ii-1][jj]){
            cout<<'U';
            ii--;
        }
        else if(a[ii][jj+1]){
            cout<<'R';
            jj++;
        }
        else
            break;
    }
    cout<<endl;
	return 0;
}
