#include<bits/stdc++.h>
using namespace std;

int a[4], ans;

int main(){
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    string n;   cin >> n;

    for(int i = 0; i < n.size(); i++)
        ans += a[n[i]-'0' - 1 ];

    return cout << ans << '\n', 0;
}