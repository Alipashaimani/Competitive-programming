// In the name of God
//code forces 200-B
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,a2;
    double ans=0;
    cin>>a;
    a2=a;
    while (a) {
        cin>>b;
        ans+=b;
        a--;
    }
    ans=ans/a2;
    cout<<ans;
}