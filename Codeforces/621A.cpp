#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,minO=1e9+10,minE=1e9+10,sum=0;
    cin >> a;
    for ( int i =0 ; i < a ; i++ ){
        cin>>b;
        sum+=b;
        b % 2 == 0 ? minE = min(minE, b) : minO = min(minO, b);
    }
    cout << (sum % 2 == 0 ? sum : (sum - minO));
}
