#include <bits/stdc++.h>
using namespace std ;

int main(){
    long long n, m, k ;
    cin >> n >> m ;
    k = n ;
    for (int i = 0;;i++){
        if (n == m)
            return cout << "YES" << '\n' << i << '\n', 0 ;
        else if (n > m)
            return cout << "NO" << '\n', 0 ;
        n *= k;
    }
}