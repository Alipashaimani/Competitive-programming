#include <bits/stdc++.h>
using namespace std;
int cnt = 0 ;
int main(){
    int n;  cin >> n;
    string s;   cin >> s;
    for (int i = n ; i < s.size() ; i+=n){
        if (s[i-1] == s[i-2] && s[i-2] == s[i-3])
            cnt++;
    }
    cout << cnt << '\n';
}