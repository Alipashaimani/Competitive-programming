//in the name of God
#include <bits/stdc++.h>
using namespace std;
string is_prime(int x){
    if ( x < 2 )
        return "not prime";
    for ( int i = 2 ; i*i <= x ; i++){
        if ( x % i == 0 )
            return "not prime";
    }
    return "prime";
}
int main(){
    int a,b,c;
    cin>>a;
    for ( int i = 2 ; ; i++){
        b=i;c=a-i;
        if ( is_prime(b)=="not prime" && is_prime(c)=="not prime"){
            cout<<b<<" "<<c;
            break;
        }
    }
    return 0;
}
