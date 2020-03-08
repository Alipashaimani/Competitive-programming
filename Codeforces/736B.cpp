#include <bits/stdc++.h>
using namespace std;
long long a;

bool is_prime(long long x){
    if ( x < 2 )
        return 0;
    for ( long long i = 2 ; i*i <= x ; i++){
        if ( x % i == 0 )
            return 0;
    }
    return 1;
}

int main(){
    cin >> a;
    if ( a == 2)
        return cout << 1 << '\n' , 0;

    if (a % 2 == 0)
        return cout << 2 << '\n', 0;

    else{
        if (is_prime(a))
            return cout << 1 << '\n',0;
        if (is_prime(a-2))
            return cout << 2 << '\n',0;
        return cout << 3 << '\n', 0;
    }
}