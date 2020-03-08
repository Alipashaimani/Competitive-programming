#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 100;
int table[MAXN][MAXN];
int dx[]{1,0,0,-1};
int dy[]{0,1,-1,0};
int n, m;
int x11,x21,y11,y21;
bool fit (int a, int b){return (a>= 0 && a < n && b >= 0 && b < m);}
void dfs(int x, int y){
    if ( table[x][y] < 1)
        return;
    for (int i = 0 ; i < 4 ; i++){
        if (fit(x+dx[i],y+dy[i])){
            table[x+dx[i]][y+dy[i]]--;
            dfs(x+dx[i], y+dy[i]);
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            char a; cin >> a;
            table[i][j] = (a=='X'?1:2);
        }
    }

    cin >> x11 >> y11 >> x21 >> y21;    --x11;--x21;--y11;--y21;
    dfs(x11,y11);
    cout << (table[x21][y21] < 1 ? "YES" : "NO") << '\n';
    return 0;
}