#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;    cin>>n>>m;
    return cout << min(n, min(m, (n + m) / 3)), 0;
}