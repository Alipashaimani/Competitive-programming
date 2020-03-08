//InhtenameofGod
//code forces 551-A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b[2010][2],maxn=0,r=1,rr=0,tt=0;
    cin>>a;
    for ( int i = 0; a > i ; i++){
        cin >> b[i][0];
        maxn=max(maxn,b[i][0]);
    }
    while (tt<a) {
    for ( int i = 0 ; a > i ; i++){
        if ( b[i][0]==maxn){
            b[i][1]=r;
            rr++;
            tt++;
        }
    }
        r+=rr;
        rr=0;
        maxn--;
    }
    for ( int i = 0 ; a > i ; i++) {
        cout<<b[i][1]<<" ";
    }
}
