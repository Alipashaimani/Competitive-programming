#include <bits/stdc++.h>
using namespace  std;
const int MAXN = 1000;
int arr[MAXN];
int ans = 0;
int main(){
    int n;  cin >> n;
    int mx, mn = 1000;
    int indexmx, indexmn;
    for ( int i = 0 ; i < n ; i++){
        int x;  cin >> x;
        if ( x == n )
            indexmx = i;
        else if (x == 1)
            indexmn = i;
    }
    ans = max(indexmn,indexmx);
    ans = max(ans,max((n-1)-indexmn,(n-1)-indexmx));
    cout << ans << endl;



}