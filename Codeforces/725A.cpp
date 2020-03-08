#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '>') {
            ans = i + 1;
            break;
        }
    }
    if (!ans) {
        cout << n << '\n';
        return 0;
    }
    for (int i = n - 1; i >= ans - 1;--i) {
        if(s[i] == '<') {
            ans = i - ans + 2;
            n -= ans;
            break;
        }
    }
    cout << n << '\n';
    return 0;
}