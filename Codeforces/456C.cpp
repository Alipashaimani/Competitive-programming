#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 100;
long long cnt[MAXN],ans[MAXN];
int main(){
    int a;
    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    ans[1] = cnt[1];
    for ( int i = 2 ; i <= 100000 ; i++ ){
        ans[i] = max(ans[i-1],ans[i-2]+cnt[i]*i);
    }
    cout << ans[100000] << '\n';
}
