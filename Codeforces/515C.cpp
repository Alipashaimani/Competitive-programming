#include <bits/stdc++.h>
using namespace std;
string a[10]{"","","2","3","322","5","35","7","7222","7332"};
int main(){
    int n;  string s;
    cin >> n >> s;
    string ans="";
    for (int i = 0 ; i < s.size(); i++){
        ans += a[s[i]-'0'];
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout << ans ;
}