#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans=0,nn=0;
    cin>>n>>m;
    for ( int i = 1 ; n+nn>=i ; i++){
        ans++;
        if ( i%m==0){
            nn++;
        }
    }
    cout<<ans;
}