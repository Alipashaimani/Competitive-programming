#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
    cin >> a >> b;
    if ( a == 0 && b == 0)
        cout << "NO\n";

    else if (abs(b-a) == 1 or abs(b-a) == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}