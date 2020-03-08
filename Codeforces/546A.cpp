
#include <bits/stdc++.h>
using namespace std;
int main (){
    int w,k,n,sum=0;
    cin>>k>>n>>w;
    for ( int i = 1 ; w+1 > i ; i++){
        sum += (i * k );
    }

    if ((sum-n)>0)
        cout<<(sum-n);
    else
        cout<<"0";
}