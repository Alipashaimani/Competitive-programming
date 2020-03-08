#include<bits/stdc++.h>
using namespace std;
int m,n,ans = 0;
int main(){
    cin >> m >> n;
    ans += m;
    for (int i = 0 ; i < m ; i++){
        int x;
        cin >> x;
        if ( x > n)
            ans++;
    }
    return cout << ans << '\n' , 0;
}