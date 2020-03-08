#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, a, b;cin>>n>>m>>a>>b;
    if (m * a <= b){
        cout << n * a ;
    }
    else {
        int j = (n / m) * b;
        n %= m;
        cout << j + min(n * a, b);
    }
}