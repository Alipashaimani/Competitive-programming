#include <iostream>
using namespace std;
int main(){
    long long a,b,m=0;
    cin>>a>>b;
    for ( int i = 1 ; a >=i ; i++){
        if ( b % i  == 0 && (b/i<=a)) m++;
    }
    cout<<m;
}