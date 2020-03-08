#include<bits/stdc++.h>
using namespace std;

int n, k;
int ans = 0;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        k += 5*i;
        if (k > 240)
            break;
        ans++;
    }
    return cout << ans << endl,0;
}