#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int x[MAXN], y[MAXN], n;
vector<int> table[MAXN];
bool marky[MAXN], markx[MAXN], mark[MAXN][MAXN];
void dfs(int xx, int yy){
    if (mark[xx][yy])
        return;
    mark[xx][yy] = true;
    markx[xx] = marky[yy] = true;
    for (int i = 0; i < n; i++)
        if (markx[x[i]] || marky[y[i]])
            dfs(x[i], y[i]);
}
int main(){

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        table[y[i]].push_back(x[i]);
    }

    dfs(x[0], y[0]);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (!(markx[x[i]] || marky[y[i]]))
            ans++;
        dfs(x[i], y[i]);
    }
    cout << ans << endl;
}