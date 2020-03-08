#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int arr[MAXN];
int mx = 0;
int ans = 0;
int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
        mx = max(mx,arr[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        ans += mx-arr[i];
    }
    cout << ans << endl;
}