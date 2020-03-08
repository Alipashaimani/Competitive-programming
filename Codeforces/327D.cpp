#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;

vector<pair<char,pair<int,int> > > ans;
string s[MAXN];
int n, m;

void dfs(int x, int y, bool t){

    if (x >= n || x < 0 || y >= m || y < 0 || s[x][y] == '#')
        return;

    s[x][y]='#';

    ans.push_back({'B',{ x+1, y+1}});

    dfs(x+1, y, 1);
    dfs(x-1, y, 1);
    dfs(x, y+1, 1);
    dfs(x, y-1, 1);

    if (t){
        ans.push_back({'D',{ x+1, y+1}});
        ans.push_back({'R',{x+1, y+1}});
    }
}


int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.')
                dfs(i, j, 0);

    cout << ans.size() << endl;

    for (int i = 0; i<ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
}