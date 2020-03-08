#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans;
bool flag;
char c;
int main(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++){
        flag=false;
        for ( int j = 0 ; j < n ; j++){
            cin>>c;
            if ( c=='0'){
                flag=true;
            }
        }
        if ( flag == true){
            a++;
            ans=max(ans,a);
        }
        else {
            a=0;
        }
    }
    cout<<ans;
    }