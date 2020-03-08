#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
int a[MAXN],pa[MAXN];
bool check (int x, int mid){
    return x > pa[mid+1];
}
int main(){
    int n,m;
    cin >> n;
    for ( int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        pa[i + 1] = pa[i] + a[i];
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        int l = -1 , r = n;
        while(l+1<r){
            int mid = ( l + r) /2;
            if (check(x,mid))
                l = mid;
            else
                r = mid;
        }
        cout << l + 2 << '\n';
    }
}