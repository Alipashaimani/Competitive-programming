#include <bits/stdc++.h>
using namespace  std;
const int MAXN = 1000;
int arr[MAXN];
int ans = 0;
int main(){
    int t,x,s;  cin >> t >> s >> x;
    if ( x>=t && x!=t+1 && (x-t)%s<2)
        return cout << "YES\n",0;
    cout << "NO\n";
}