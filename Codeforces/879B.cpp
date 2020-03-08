#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
ll a[MAXN], cnt, mx, id, n,k ;
int main () {
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
        if (a[id] < a[i])
            id = i;

    }
    if ( k > id )
        return cout << a[id], 0;

    for (int i = 1 ; i < id ; i++){
        if (a[mx] > a[i]){
            cnt++;
            if ( cnt == k )
                return cout << a[mx] << '\n', 0;
        }
        else{
            cnt = 1;
            mx = i;
        }
    }
    cout << a[id] << '\n';
}