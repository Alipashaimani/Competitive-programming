#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, maxn = 0, minn1 = 0, minn2 = 0   ;
    cin >> a >> b;
    maxn =  a - (b - 1);
    maxn = (((maxn-1) + 1)*(maxn-1))/2;

    minn1 = b - (a % b) ;
    minn1 = ((( ( (a / b) - 1 ) + 1) * ((a / b) - 1)) / 2) * minn1;
    cerr << minn1 << '\n' ;

    minn2 =  (a % b);
    minn2 = ((((( (a / b) + 1) ) - 1) + 1) * ((( (a / b) + 1) ) - 1) / 2) * minn2;
    cerr << minn2 << '\n';
    minn2 += minn1 ;

        cout << minn2 << " " << maxn ;
}
