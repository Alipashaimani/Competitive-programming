#include <bits/stdc++.h>
using namespace std;
map < long long  , pair<bool,bool> > m;
long long is_prime(long long x){
    if ( x < 2 )
        return 0;
    for ( long long i = 2 ; i*i <= x ; i++){
        if ( x % i == 0 )
            return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long r;
    cin>>r;
    for ( long long i = 0 ; r > i ; i++){
        long long a;
        cin>>a;
        if (m[a] .first == 1 ) {
            cout << (m[a].second == 1 ? "YES" : "NO") << '\n';
            continue;
        }
        long long b=sqrt(a);
        m[a].first = 1 ;
        m[a].second = (b*b ==a && is_prime(b)==1 ?1:0);
       	cout << (m[a].second == 1 ? "YES" : "NO") << '\n';
    }

}
