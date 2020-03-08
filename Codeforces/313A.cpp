#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if ( a>=0)
        cout<<a;
    else{
        int b=a/10;
        int c=(a/100)*10 + a%10;
        cout<<max(c,b);
    }


}
