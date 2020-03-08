#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,ab;
    cin>> a>>b>>c;
    ab=abs(abs(a)+abs(b));
    cerr<<ab<<endl;
    if ( ab> c ){
        cout<<"No";
    }
    else {
        if (ab%2==0&& c%2==0){
            cout<<"Yes";
        }
        else if ( ab%2==1 && c%2==1){
            cout<<"Yes";
        }
        else {
            cout<<"No";
        }
    }
}