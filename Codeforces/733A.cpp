#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int cnt = 0, MAXN = 0;
    for (int i = 0; i < s.size() ; i++){
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
            MAXN = max(MAXN, cnt);
            cnt = 0;
            continue;
        }
        cnt++;
    }
    MAXN = max(MAXN, cnt);
    cout << MAXN + 1;
    return 0;
}