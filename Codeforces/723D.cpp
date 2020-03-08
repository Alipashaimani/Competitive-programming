#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50+10;
string c[MAXN];
bool vis[MAXN][MAXN];
int n,m,k,ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool flag ;
bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m && c[a][b] == '.' && !vis[a][b];}
set<pair<int , pair<int,int > > > position;
int cnt;
void dfs(int x , int y){
	if ( x == 0 || y == 0 || x == n-1 || y == m-1)	flag = 1;
	cnt++;
	vis[x][y] = 1;
    for (int i = 0 ; i < 4 ; i++ )
        if (fit(x+dx[i] , y + dy[i]))
            dfs(x+dx[i] , y+dy[i]) ;
}

void cng (int x, int y){
	c[x][y] = '*';
	for ( int i = 0 ; i < 4 ; i++)
	 if (fit(x+dx[i] , y + dy[i]))
		cng(x+dx[i] , y+dy[i] );
}
int main(){
    cin >> n >> m >> k;
    for ( int i = 0 ; i < n ; i++)	cin >> c[i];

    for ( int i = 0 ; i < n ; i++)
        for ( int j = 0 ; j < m ; j++)
            if ( c[i][j] == '.' && !vis[i][j]){
				flag = false;
				cnt = 0;
                dfs(i,j);
				if (!flag)
					position.insert({cnt,{i,j}});
			}

	fill(vis[0], vis[0] + MAXN * MAXN, 0);
	while (position.size() > k){
		ans+=position.begin()->first;
		cng(position.begin()->second.first, position.begin()->second.second);
		position.erase(position.begin());
	}
	cout << ans << '\n' ;
	for ( int i = 0 ; i < n ; i++)
		cout << c[i] << '\n';
	return 0;
}

