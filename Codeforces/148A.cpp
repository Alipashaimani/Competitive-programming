#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,r=0;cin>>a>>b>>c>>d>>e;
    for ( int i = 1 ; e>= i ; i++){
        if ( i%a==0 || i%b==0 || i%c==0 || i%d==0){
            r++;
        }
    }
    cout<<r;
}
