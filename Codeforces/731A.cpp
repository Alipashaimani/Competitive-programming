#include <bits/stdc++.h>
using namespace std;
int ans = 0,cur;
int main(){
    string s;   cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ans += min(26 - abs(s[i] - 'a' - cur), abs(s[i] - 'a' - cur));
        cur = s[i] - 'a';
    }
    cout << ans << endl;
}