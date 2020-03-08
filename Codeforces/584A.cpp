//in the name of God
//code forces-584A
#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    cin>>a>>b;
    if (a==1 && b == 10){
        cout<<-1;
    }
    else {
        if ( b == 10 ){
            a--;
        }
        cout<<b;
        for ( int i = 0 ; a-1 > i ; i++){
            cout<<0;
        }
    }
}
