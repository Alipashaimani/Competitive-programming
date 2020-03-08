#include <bits/stdc++.h>
#define B begin()
#define E end()
#define pp push_back
using namespace std;
int n,m,f[100],r=1e7,j;
int main() {
    cin>>n>>m;
    for ( int i = 0 ; m > i ; i++){
        cin>>f[i];
    }
    sort(f,f+m);
    for (int i = 0 ; m-n >= i ; i++){
        j=f[i+n-1]-f[i];
        r=min(r,j);
    }
    cout<<r;
}