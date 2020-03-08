#include <bits/stdc++.h>
using namespace std ;

int mn = 1e9;
vector<int> ans;
int n , m;
string s , t;
int main(){
    cin >> n >> m >> s >> t;
    for(int i = 0; i <= m - n; i++){
        int cnt = 0;
        vector<int> v;
        for(int j = i; j < i + n; j++)
            if(s[j - i] != t[j]){
                v.push_back(j - i + 1);
                cnt++;
            }
        if(cnt < mn){
            mn = cnt;
            ans = v;
        }
    }
    cout << mn << '\n';
    for(auto x : ans)
        cout << x << " ";
}