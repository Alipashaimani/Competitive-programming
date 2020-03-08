//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b[1000];
    cin>>a;
    for ( int i = 0 ; a > i ; i++){
        cin>>b[i];
    }
    sort(b,b+a);
    for ( int i = 0 ; a > i ; i++){
        cout<<b[i]<< " ";
    }
    return 0;

}
