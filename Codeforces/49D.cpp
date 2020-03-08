#include<bits/stdc++.h>
using namespace std;

string s;
int n, ans;

int main(){
    cin >> n >> s;
    for(int i = 1; i < n ;i++)
        if(s[i] == s[i-1]){
            s[i]^=1;
            ans++;
        }
    cout << min(ans, n-ans);
}