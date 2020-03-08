//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if ( (a>=b && b%2==1) || (b>a && a%2==1)){
        cout<<"Akshat";
    }
    else {
        cout<<"Malvika";
    }
}
