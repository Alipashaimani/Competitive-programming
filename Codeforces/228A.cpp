#include <bits/stdc++.h>
using namespace std;
long long a[4];
int x;
int main(){
    for ( int i = 0 ; 4 > i ; i++){
        cin>>a[i];
    }
    for ( int i = 0 ; 4 > i ; i++){
        for ( int j = i+1 ; 4 > j ; j++){
            if ( a[i]==a[j]){
                x++;
                break;
            }
        }
    }
    cout<<x;
}