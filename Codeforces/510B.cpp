#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
bool mark[MAXN][MAXN];
char table[MAXN][MAXN];
bool flag = false;
int n, m;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
bool fit ( int a, int b){return a>= 0 && a < n && b >= 0 && b < m ;}
void dfs(int x, int y, int a = -1, int b = -1){
	mark[x][y] = true;
	for ( int i = 0 ; i < 4 ; i++){
		if ( fit(dx[i] + x , dy[i] + y ) && table[x][y] == table[x+dx[i]][y+dy[i]] && (x+dx[i] != a || y+dy[i] !=  b )){
			if (mark[x+dx[i]][y+dy[i]])
				flag = true;
			else
				dfs(x+dx[i],y+dy[i],x,y);
		}
	}
}
int main(){
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < m ; j++){
			cin >> table[i][j];
		}
	}
	for ( int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < m ; j++){
			if (!mark[i][j])
				dfs(i,j);
		}
	}
	cout << (flag?"Yes":"No") << '\n';
	return 0;
}