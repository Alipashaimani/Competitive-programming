//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,sum=0,cnt=0,k=0;
    cin>>a;
    vector<int>b;
    for ( int i = 0 ; 12>i ; i++){
        int x;
        cin >> x;
        sum+=x;
        b.push_back(x);
    }
    if ( sum<a){
        cout<<-1;
    }
    else {
        sum=0;
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        for (int i = 0;12>i;i++){
            if(sum<a){
                sum+=b[i];
                cnt++;
            }
           // cout<<sum<< " "<<a;
            if ( sum >= a){
                cout<<cnt;
                k=1;
                break;
            }
        }
        if ( k == 0 ){
            cout<<-1;
        }
    }
}