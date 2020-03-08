#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0,b=0,c;cin>>c;
    for ( int i = 1 ;; i++){
        a=(a+i);
        b+=a;
        if ( c < b){
            cout<<i-1;
            break;
        }
    }
}
