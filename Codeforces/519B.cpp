#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
long long a, b, c;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        long long x;
        cin >> x;
        a+=x;
    }
    for (int i = 0 ; i < n-1 ; i++){
        long long x;
        cin >> x;
        b+=x;
    }
    for (int i = 0 ; i < n-2 ; i++){
        long long x;
        cin >> x;
        c+=x;
    }
    return cout << a - b <<'\n' << b - c << '\n', 0 ;

}