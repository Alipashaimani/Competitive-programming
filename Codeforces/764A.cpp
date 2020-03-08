#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main(){
    int n, m, c;

    cin >> n >> m >> c;
    for ( int i = 1 ; i<= c ; i++){
        if ( i % n == 0 && i % m == 0)
            ans ++;
    }
    cout << ans  << endl;


    return 0;
}