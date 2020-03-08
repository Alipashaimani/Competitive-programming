#include <bits/stdc++.h>
using namespace std;
long long a,b,r;
int main(){
    cin>>a>>b;
    if ( a % 2 == 1){
        r=(a/2)+1;
    }
    else {
        r=a/2;
    }
    if ( b > r){
        cout<<((b-r)*2);
    }
    else {
        cout<<(b*2)-1;

    }
}
