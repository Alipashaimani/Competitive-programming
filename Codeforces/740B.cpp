#include <bits/stdc++.h>
using namespace std;
int ans[10000];
int javab[10000];
int main(){
    int a,b,maxn = 0;
    cin >> a >> b;
    int y ;
    cin >> y;
    ans[1] = y;
    for ( int i = 1; i < a ; i++){
        int x;
        cin >> x;
        ans[i+1] = ans[i]+x;
    }
    for ( int i = 0 ; i < b ; i++){
        int t1,t2;
        cin >> t1 >> t2;

        javab[i] = ans[t2] - ans[t1-1];
    }
    for ( int i = 0 ; i < b ; i++){
        if ( javab[i] > 0){
            maxn += javab[i];
        }
    }
    cout << maxn;
}