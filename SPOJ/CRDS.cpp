#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000007;
long long t;
int main(){
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n;
        k = 3 * ((n * (n + 1))/2) - n;
        k = k % MOD;
        cout << k << '\n';
    }
}
