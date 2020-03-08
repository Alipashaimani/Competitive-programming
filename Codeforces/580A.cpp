#include <bits/stdc++.h>
using namespace std;
int main(){
int a,ans = 1, maxn=1;
cin >> a;
int b[a+5];
for ( int i = 0 ; i < a ; i++ )
    cin>>b[i];
for ( int i = 1 ; i < a ;i++ ) {
    if ( b[i]>=b[i-1] ) {
        ans++;
        maxn=max(maxn,ans);
    }
    else
        ans=1;
}
cout<<maxn;


}
