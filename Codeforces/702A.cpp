#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,ans = 1, maxn=1;
    cin >> a;
    long long b[a+5];
    for ( long long i = 0 ; i < a ; i++ )
        cin>>b[i];
    for ( long long i = 1 ; i < a ;i++ ) {
        if ( b[i]>b[i-1] ) {
            ans++;
            maxn=max(maxn,ans);
        }
        else
            ans=1;
    }
    cout<<maxn;


}