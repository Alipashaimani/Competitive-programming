//InTheNameOfGOD
#include <bits/stdc++.h>
using namespace std;

long long n,ans=0;

int main(){
    cin>>n;

    for(long long i = 1; i<=n ;i*=10)
        ans += n-i+1;

    return cout << ans << '\n',0;
}