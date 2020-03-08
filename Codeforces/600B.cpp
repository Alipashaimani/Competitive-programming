#include<bits/stdc++.h>
using namespace std;
const int MAXN =( 1e5 * 2 ) + 100;
long long a[MAXN], b[MAXN];
bool check(int i,int mid){
    if (b[i] >= a[mid]){
        return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++)
        cin >> a[i];
    for ( int i = 0 ; i < m ; i++)
        cin >> b[i];
    sort(a,a+n);
    for ( int i = 0 ; i < m ; i++){
        int l = -1 ,r = n;
        while(l+1<r){
            int mid = ( l + r) /2;
            if (!check(i,mid))
                r = mid;
            else
                l = mid;
        }
        cout << l+1 << " ";
    }
    cout << '\n';
    return 0;
}