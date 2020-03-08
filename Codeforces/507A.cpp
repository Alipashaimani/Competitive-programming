#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int sum=0,cnt=0;
    bool out=0;
    pair < int , int > c[1010];
    cin >> a >> b;
    for ( int i = 0 ; i < a ; i++ ) {
            cin>>c[i].first;
            c[i].second=i+1;
            }
            sort(c,c+a);
            for ( int i = 0 ; i < a ; i++ ){
            sum+c[i].first <= b ?(sum+=c[i].first , cnt++) : out=1 ;
            if ( out == 1 )
                break;
        }
            cout<<cnt<<'\n';
            for ( int i = 0  ; i < cnt ;i++ ) {
                cout<<c[i].second<<" ";
}
}
