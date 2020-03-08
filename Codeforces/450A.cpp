#include <bits/stdc++.h>
#define B begin()
#define E end()
#define pp push_back
using namespace std;
int n,m,f[120],j=0,r;
int main() {
    cin>>n>>m;
    for ( int i = 0 ; n > i ; i++){
        cin>>f[i];
    }
    for ( int i = 0 ;j<n;){
        if ( f[i]<= m && f[i]!=-5){
            f[i]=-5;
            j++;
            r=i+1;
        }
        else if(f[i]!=-5){
            f[i]=f[i]-m;
        }
        if ( i+1 >= n){
            i=0;
        }
        else {
            i++;
        }
    }
    cout<<r;
}

