#include <iostream>
using namespace std;
int main(){
    int a;int c1,c2,m=0,minn=1000;
    cin>>a;
    for ( int i = 0 ; a > i ; i++){
        cin>>c1>>c2;
        minn=min(c2,minn);
        m+=(c1*minn);
    }
    cout<<m;
}