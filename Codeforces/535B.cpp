#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    string b;
    cin>>b;
    a=(pow(2,b.size()))-1;
    for (int i=0;b.size()>i;i++){
        if(b[i]=='7'){
            a+=(pow(2,b.size()-i-1));
        }
    }
    cout<<a;
}