#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,minn;
    cin>>a>>b>>c;
    for ( int i = 0 ;c >= i ;i++){
        minn=min(a*i,b*i);
        for( int j = 0 ; c-minn >= j ; j++){
            if ( i*a + j*b == c || i*b + j*a ==c){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
}