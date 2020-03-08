#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5;
int m, n, k, x, y;
char a[MAXN][MAXN];
bool mark[MAXN][MAXN];
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool check (int x, int y){return !mark[x][y] && a[x][y]=='.';}
void dfs(int x,int y){
    mark[x][y] = true;
    for (int i=0;i<4;i++)
        if (check(x+mv[i][0],y+mv[i][1]))
            dfs(x+mv[i][0], y+mv[i][1]);
    if (k-- > 0)
        a[x][y]='X';
}

int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.')
                x=i, y=j;
        }
    dfs(x,y);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j];
        cout<<'\n';
    }
}