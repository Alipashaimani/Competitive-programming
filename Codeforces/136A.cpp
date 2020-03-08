#include <bits/stdc++.h>
using namespace std;
int a,f[110],m=1;
int main(){
    cin >> a;
    for ( int j = 0 ; a > j ; ++j){
        cin>>f[j];
    }
    int i = 0 ;
    while (m!=a+1) {
        if ( f[i]==m){
            m++;
            cout<<i+1<< " ";
        }
        if ( i > a){
            i=0;
        }
        else {
            i++;
        }

    }
}
