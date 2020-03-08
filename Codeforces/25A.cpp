//code forces 25-A
#include<bits/stdc++.h>
using namespace std;
int Ocount=0,Ecount=0,Ei,Oi;
int main(){
    int a,b;
    cin>>a;
    for ( int i = 0 ; a > i ; i++){
        cin>>b;
        if ( b % 2 == 0 ){
            Ei=i+1;
            Ecount++;
        }
        else {
            Oi=i+1;
            Ocount++;
        }
    }
    if ( Ecount == 1){
        cout<<Ei;
    }
    else {
        cout<<Oi;
    }
}