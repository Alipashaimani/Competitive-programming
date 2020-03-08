#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,r=0;
    cin>>a>>b;
    for ( long long i = 0 ; i < a ; i++){
        char c;
        long long x;
        cin>>c >> x;
        if ( c == '+'){
            b+=x;
        }
        else if (b-x >= 0 ){
            b-=x;
        }
        else {
            r++;
        }
        cerr<<b<<" "<<r<<endl;
    }
    cout<<b<<" "<<r;
}