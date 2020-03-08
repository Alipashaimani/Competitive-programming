#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string>ss;
    int m,a,r,u=0;
    cin>>a;
    for ( int i = 0 ;a>i ; i++ ){
        cin>>r;
        u=360%(180-r);
        cout<<(u==0?"YES":"NO")<<endl;

    }
}