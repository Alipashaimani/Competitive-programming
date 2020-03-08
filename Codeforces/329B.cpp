#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
const int INF = 1e9;

int n, m;
char c[MAXN][MAXN];
int d[MAXN][MAXN];
pair<int, int>	s, e, q[MAXN * MAXN];
bool mark[MAXN][MAXN];

int dx[]{+1,-1,0,0};
int dy[]{0,0,+1,-1};

bool fit(int a,int b){return a < n and a >= 0 and b < m and b  >= 0 and mark[a][b] == 0 and c[a][b] != 'T';}

void bfs(){

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = INF;

    int h = 0, t = 0;

    mark[e.first][e.second] = 1;
    d[e.first][e.second] = 0;
    q[t++] = e;

    while (h < t){
        pair<int, int>	x = q[h++];
        int row = x.first, col = x.second;
        for (int i = 0 ; i < 4 ; i++){
            if (fit(row + dx[i], col + dy[i])){
                q[t++] = {row + dx[i], col + dy[i]};
                d[row + dx[i]][col + dy[i]] = d[row][col] + 1;
                mark[row + dx[i]][col + dy[i]] = 1;
            }
        }
    }
}

int main(){

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j] ;

            if (c[i][j] == 'E')
                e = {i, j};

            if (c[i][j] == 'S')
                s = {i, j};
        }
    }

    bfs();

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (d[i][j] <= d[s.first][s.second] && c[i][j] <= '9')
                ans += c[i][j] - '0';

    return cout << ans << endl, 0;
}