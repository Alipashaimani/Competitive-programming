#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int cnt = 1;
    int t = n;
    while (t % 10 != 0 && t % 10 != k){
        t += n;
        cnt++;
    }
    cout << cnt;
}
