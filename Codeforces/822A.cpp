#include <bits/stdc++.h>
using namespace std;

int f[13];

int main(){

    f[0]=1;
    for (int i = 1 ; i < 13 ; i++)
        f[i]=f[i-1]*i;

    int a, b;    cin>>a>>b;
    return cout << f[min(a, b)] ,0;
}