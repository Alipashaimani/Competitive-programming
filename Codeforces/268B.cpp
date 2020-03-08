// 268 _ B
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a ,b , ans = 0 ;
    cin >> a ;
    b = a;
    ans = (( a * (a + 1) )/2);
    cerr << ans << " " ;
    for ( int i = 0 ; i < a-1; i++){
        ans += ( i * --b);
    }
    cout << ans;
}