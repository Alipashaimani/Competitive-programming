// In the name of God
//code forces 678-A
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    long long c=a-(a%b);
    for ( long long i = c ; ; i+=b ){
        if ( i != 0 && i % b == 0 && i>a){
            cout<<i;
            return 0;
        }
    }
}
