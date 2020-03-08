//in the name of God
#include <bits/stdc++.h>
using namespace std;
int a,h[1000],g[1000],ans;
int main(){
    cin>>a;
    for ( int i = 0 ; a > i ; ++i){
        cin>>h[i]>>g[i];
    }
    for ( int i = 0 ; a > i ; ++i){
        for ( int j = 0 ; a > j ; ++j){
            if ( h[i]==g[j])
                ans++;
        }
    }
    cout<<ans;
}
