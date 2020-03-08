#include <iostream>

using namespace std;

int main(){
    long long int a,b,c;
    cin>>a>>b>>c;
    if(a%c!=0)
        a=a/c+1;
    else
        a=a/c;
    if(b%c!=0)
        b=b/c+1;
    else
        b=b/c;
    cout<<a*b;
}