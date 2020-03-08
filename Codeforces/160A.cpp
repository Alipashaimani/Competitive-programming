#include <bits/stdc++.h>
using namespace std;

bool cmt  ( int a,int b){
    return a>b;
}
const int MAXN = 1000;
int a,b[MAXN],cnt = 0,h = 0,ans = 0;
int main(){
    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        cin >> b[i];
        cnt += b[i];
    }
    sort(b,b+a,cmt);

    for ( int i = 0 ; i < a ; i++){
        if ( h <= cnt ){
            h += b[i];
            cnt -= b[i];
            ans++;
        }
        if ( h > cnt){
            cout << ans;
            return 0;
        }
    }
}
