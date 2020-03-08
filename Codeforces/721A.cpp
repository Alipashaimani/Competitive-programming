#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
string s;
vector<int> ans;
int main(){
    cin >> n >> s;
    for (int i = 0; i <= n; ++i) {

        if (cnt && (i == n || s[i] == 'W'))
            ans.push_back(cnt);

        if (s[i] == 'B' && i!= n)
            cnt++;

        else if (i != n)
            cnt = 0;
    }
    cout << ans.size() << '\n';

    for(int i = 0 ; i < ans.size() ; i++)
        cout << ans[i] << " ";

    return 0;
}
