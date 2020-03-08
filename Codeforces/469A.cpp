//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,p,q,x,u=1;
    vector<int>b;
    cin>>a>>p;
    for ( int i = 0 ; p > i ; i++){
        cin>>x;
        b.push_back(x);
    }
    cin>>q;
    for ( int i = 0 ; q > i ; i++){
        cin>>x;
        b.push_back(x);
    }
    sort(b.begin(),b.end());
    for ( int i = 0 ; b.size()>i ; i++){
        if ( b[i]==u){
            u++;
        }
    }
  //  cout<<u <<" "<<a<<" ";
    cout<< ( u==(a+1)?"I become the guy.":"Oh, my keyboard!");

}