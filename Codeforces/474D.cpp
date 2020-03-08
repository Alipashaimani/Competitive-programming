#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long arr[100000+100],sumN[100000+123];

long long f(long long n,long long r){
    if ( n < r )
        return 1;
    if ( arr[n])
        return arr[n];
    else {
        arr[n]=(f(n-1,r)+f(n-r,r))% mod;
        return arr[n];
    }
}
int main(){

    long long a, b;
    cin >> a >> b;
    for ( int i = 1 ; i <= 100000 ; i++){
        sumN[i] = (sumN[i-1] + f(i,b)) % mod ;
    }
    for ( long long i = 0 ; i < a ; i++){
        long long sum = 0 ;
        long long x ,y;
        cin >> x >> y;

        sum = ( sumN [y] - sumN[x - 1] + mod) % mod;
        cout << (sum % mod) << '\n';
    }

}
