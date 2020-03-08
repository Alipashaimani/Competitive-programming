#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, ans = 0;
    cin >> a;
    string s,ss;
    cin >> s >> ss;
    for ( int i = 0 ; i < a ; i++ ){
        int x = abs ( ss[i]-s[i] ) ;
        int y = abs ( 10 - x ) ;
        ans += ( min(x, y) ) ;
    }
    cout << ans;
}
