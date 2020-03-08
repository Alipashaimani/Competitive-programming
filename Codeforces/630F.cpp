#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
map<pair<ll,ll>, ll> mpi;
ll ca(ll a,ll b){
    if ( b > a)
        return 0;
    if (b == 0)
        return 1;
    if (!mpi[pair<ll,ll>(a-1,b-1)])
        mpi[pair<ll,ll>(a-1,b-1)] = ca(a-1,b-1);
    if (!mpi[pair<ll,ll>(a-1,b)])
        mpi[pair<ll,ll>(a-1,b)] = ca(a-1,b);
    return mpi[pair<ll,ll>(a-1,b)] + mpi[pair<ll,ll>(a-1,b-1)];
}
int main(){
    ll n ;
    cin >> n;
    return cout << ca(n,5) + ca(n,6) + ca(n,7) <<'\n' , 0;
}