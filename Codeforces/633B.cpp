#include <bits/stdc++.h>
using namespace std;

int n, ans, a;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 5; ans < n; i += 5) {
        int t = i;
        while (!(t % 5)){
            t /= 5;
            ans++;
            a = i;
        }
    }
    if (ans > n)
        return cout << 0 << '\n', 0;

    cout << 5 << '\n';
    for (int i = 0; i < 5; i++)
        cout << a + i << " ";

    cout << '\n';
    return 0;
}