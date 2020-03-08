#include <iostream>
using namespace std;
long long a, b, k;

bool check(long long a, long long b, long long L, long long mid, long long t , long long m){
    L--;mid--;
    long long sum = (mid * (mid - 1) - L * (L - 1)) / 2;
    if (a * (mid - L) + sum * b <= t * m &&  a + (mid - 1) * b <= t )
        return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> a >> b >> k;

    while (k--){

        long long L, t, m;
        cin >> L >> t >> m;
        long long l = L, r = 1e6 + 1000;

        while (l+1 < r){
            long long mid = (l + r) / 2;

            if (check(a, b, L, mid, t, m))
                l = mid;

            else
                r = mid;
        }

        cout << ( l == L ? -1 : l - 1) << '\n';
    }
    return 0;
}