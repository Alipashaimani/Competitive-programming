#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,m=0,r=0;
    cin>>a>>b;
    for ( int i = 0 ; a > i ; i++){
        int x;
        cin>>x;
        m+=x;
        cerr<<m<<endl;
        if ( i + 1 < a ){
            m+=10;
            r+=2;
        }
        cerr<<m<<endl;
    }
    if ( m > b){
        cout<<-1;
    }
    else {
        b=b-m;
        r+=(b/5);
        cout<<r;
    }
}