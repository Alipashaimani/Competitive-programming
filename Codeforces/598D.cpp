#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 100;
int n,m,q,c = 1 , cnt = 0;
char table[MAXN][MAXN];
int mark[MAXN][MAXN];

pair<int,bool>ans[MAXN][MAXN];
vector<int> ColorAns;

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

bool fit (int a , int b){return 0 <= a && a < n && 0 <= b && b < m ;}

void dfs(int x, int y, int color){
    mark[x][y] = color;
    ans[x][y].second = true;
    ans[x][y].first = color;
    for (int i = 0; i < 4; i++)
        if (fit(x+dx[i] , y +dy[i])){

            if (table[x+dx[i]][y+dy[i]] == '*')
            cnt++;

            else if (mark[x+dx[i]][y+dy[i]] != color)
                dfs(x+dx[i],y+dy[i],color);
        }

}

int main(){
    ColorAns.push_back(-1);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> table[i][j];

    for (int i = 0; i < q; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        if (ans[x][y].second == true){
            cout << ColorAns[ans[x][y].first] <<'\n';
            continue;
        }
        cnt = 0;
        dfs(x ,y , c);
        ColorAns.push_back(cnt);
        c++;
        cout << cnt << '\n';
    }
}

