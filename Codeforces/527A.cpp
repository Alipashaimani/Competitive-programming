#include <bits/stdc++.h>
#define B begin()
#define E end()
#define pp push_back
using namespace std;
long long a,b,c,ans;
int main() {
    cin >> a >> b;
    while (b > 0) {
        ans += (a/b);
        c = a % b;
        a = b;
        b = c;
    }
    cout<<ans;
}