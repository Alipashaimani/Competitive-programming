#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+100;
long long arr[MAXN];
int n;
int main(){
    long long ans = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    sort(arr+1,arr+n+1);

    for (int i = 1 ; i < n ; i++){
        ans += (arr[i] * (i+1));
    }
    ans += arr[n]*n;
    cout << ans << endl;

}