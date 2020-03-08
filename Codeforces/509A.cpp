#include <bits/stdc++.h>
using namespace std;

int ca(int n, int r){
    if (r > n )
        return 0;

    if (r == 0)
        return 1;

    return ca(n - 1, r - 1) + ca(n - 1, r);

}
int main(){
        int n ;
        cin >> n ;
        n-=1;
        cout<<ca(2*n,n);

}