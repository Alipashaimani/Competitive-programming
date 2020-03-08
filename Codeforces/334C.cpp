#include <bits/stdc++.h>
using namespace std;

long long f (long long n){
    if (!(n % 3))
        return f(n/3);
    return n/3 + 1;
}

int main(){
    long long n;    cin>>n;
    return cout<<f(n)<<'\n',0;
}