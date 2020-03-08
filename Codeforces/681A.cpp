#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    for  (int i = 0 ; a > i ; i++){
        string s;
        int bi,ai;
        cin>>s>>bi>>ai;
        if ( ai > bi && bi >= 2400){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}