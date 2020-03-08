#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
typedef long long ll;
#define F first
#define S second
map<int,pair<ll,ll> > mip;
pair<int,int> arr[MAXN];
int m;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> m;
    for (int i = 1 ; i <= m ; i++){
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr+1,arr+m+1);
    for (int i = 1 ; i<= m ; i++){
        ll m1 = min((i+1<= m ? (abs(arr[i+1].F - arr[i].F)) : INFINITY),(i-1>= 1 ? (abs(arr[i].F - arr[i-1].F)) : INFINITY)) ;
        ll m2 = max(abs(arr[i].F - arr[1].F ), abs(arr[m].F - arr[i].F));
        mip[arr[i].S] = pair<ll,ll>(m1,m2);
    }
    for (auto p:mip){
        cout << p.S.F << " " << p.S.S << '\n';
    }
    return 0;
}