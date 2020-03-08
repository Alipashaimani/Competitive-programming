#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int ans[MAXN], m;
string s;

bool dfs(int st, int p){

    if(st > m)
        return 1;

    for(int i = p + 1; i <= 10; i++){
        if(s[i-1] == '1' && ans[st-1] != i){
            ans[st] = i;
            if(dfs(st+1, i - p))
                return 1;
        }
    }
    return 0;
}

int main() {
    cin >> s >> m;

    if(dfs(1, 0)){
        cout << "YES\n";
        for(int i = 1; i <= m; i++)
            cout << ans[i] << " ";
        return 0;
    }
    return cout << "NO\n",0;
}