#include <bits/stdc++.h>
using namespace std;

int a,b;

int main(){
    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        int x;  cin >> x;
        long long ans = x*(x+1LL)/2LL;
        ans -= 2*((pow(2,int(log2(x))+1LL))-1LL);
        cout << ans << endl;
    }
}