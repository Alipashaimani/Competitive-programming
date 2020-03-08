#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 200;

int main(){
    int n, k, t;  cin >> n >> k  >> t ;
    if(t <= k)
        return cout << t, 0;
    if(t > n )
        return cout << k - (t - n ),0;
    cout << k ;
}