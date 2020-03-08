#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 100;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m,n;
int name =  0;
int cnt;
pair<char , int > c[MAXN][MAXN];
vector<int>comp;
int markcomp[MAXN*MAXN];
bool mark[MAXN][MAXN];
bool fit (int a , int b){return 0 <= a && a < n && 0 <= b && b < m && c[a][b].first == '.'; }

void dfs ( int x, int y){
	cnt ++;
	mark[x][y] = true;
	c[x][y].second = name;
	for ( int i = 0 ; i < 4 ; i++)
		if (fit(x+dx[i],y+dy[i]) && !mark[x+dx[i]][y+dy[i]])
			dfs(x+dx[i] , y + dy[i]);
}
int main(){
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < m ; j++)
			cin >> c[i][j].first;
	for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < m ; j++)
			if ( c[i][j].first == '.' && !mark[i][j] ){
				cnt = 0;
				dfs(i,j);
				comp.push_back(cnt);
				++name;
			}

	int cc = 1;
	for ( int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < m ; j++){
			if ( c[i][j].first == '*' ){
				int ans = 1;
				for ( int k = 0 ; k < 4 ; k++){
					if ( fit(i+dx[k],j+dy[k]) && markcomp[c[i+dx[k]][j+dy[k]].second] < cc ) {
						ans += comp[c[i+dx[k]][j+dy[k]].second];
						markcomp[c[i+dx[k]][j+dy[k]].second] = cc;
					}
				}
				cout << char(ans%10 + '0');
			}
			else
				cout << '.';
			cc++;
		}
		cout << "\n";
	}
	return 0;
}
