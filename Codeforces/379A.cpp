#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans=0;
    cin>>a>>b;
    ans+=a;
    while (a!=1) {
        ans+=a/b;
        a=(a/b)+(a%b);
        if (a<b){
            break;
        }

    }
    cout<<ans;



}