//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,r,u,t=0;
    cin >> a;
    for ( int i = 0 ; a > i ; i++){
        cin>>r>>u;
        if ( r == u){t++;}
    }
    cout<<(a==t?"Poor Alex":"Happy Alex");
}
