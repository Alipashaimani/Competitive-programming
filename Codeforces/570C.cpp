#include <bits/stdc++.h>
using namespace std;

int n,q;
int l = 0, ans = 0;
string s;

int main(){
    cin >> n >> q >> s;

    for (int i = 0; i < s.size(); i++)
        if (s[i]=='.')
            l++;

        else{
            ans += (l>0)?(l-1):0;
            l = 0;
        }

    ans += (l > 0) ? (l - 1) : 0;

    while (q--){
        int k; char c;
        cin >> k >> c;
        k--;
        if (c == '.'){
            if (s[k] != '.'){
                s[k] = '.';

                if (s[k-1] == '.')
                    ans++;

                if (s[k+1] == '.')
                    ans++;

            }
        }
        else{
            if (s[k] == '.'){
                s[k] = c;
                if (s[k+1] == '.')
                    ans--;

                if (s[k-1] == '.')
                    ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}