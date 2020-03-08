#include<bits/stdc++.h>
using namespace std;
long long m,ans = 0;
int main(){
    cin >> m ;
    while(m){
        if ( m & 1)
            ans++;
        m/=2;
    }
    return cout << ans << '\n' , 0;
}