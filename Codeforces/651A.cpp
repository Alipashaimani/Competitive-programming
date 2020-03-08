#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;    cin>>a>>b;
    if(a == b && a == 1)
        return cout<< 0, 0;

    int ans = 0;
    while(a && b){
        if(a > b)
            swap(a, b);
        a++;
        int k = max(a, b);
        b = max(0, b - 2);
        if(max(a - 1, k) - 1)
            ans++;
    }
    return cout << ans << '\n', 0;
}