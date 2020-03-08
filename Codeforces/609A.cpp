#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c[10000];
    cin >> b >> a;
    for ( int i = 0 ; b > i ; i++){
        int x;
        cin>>x;
        c[i]=x;
    }
    sort(c,c+b);
    reverse(c,c+b);
    int ans=0,r=0;
    for ( int i = 0 ; ; i++){
        cerr<<ans<<'\n';
        if ( ans>=a)
            break;
        else {
            ans+=c[i];
            r++;

        }

    }
    cout << r;
}