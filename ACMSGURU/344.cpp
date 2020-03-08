#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1000 + 10;
short int val[maxn][maxn];
int n, m;
char T[maxn][maxn];

void dfs(int x, int y){
	val[x][y] = 2;
	val[x - 1][y] ++;
	if(x > 1 && val[x - 1][y] == 2)
		dfs(x - 1, y);
	val[x + 1][y] ++;
	if(x < n && val[x + 1][y] == 2)
		dfs(x + 1, y);
	val[x][y - 1] ++;
	if(y > 1 && val[x][y - 1] == 2)
		dfs(x, y - 1);
	val[x][y + 1] ++;
	if(y < m && val[x][y + 1] == 2)
		dfs(x, y + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector <pie> x;
	reu(i, 1, n){
		reu(j, 1, m){
			cin >> T[i][j];
			if(T[i][j] == 'X')
				x.pb(mp(i, j));
		}
	}
	rep(i, x.size())
		if(val[x[i].p1][x[i].p2] < 2)
			dfs(x[i].p1, x[i].p2);
	int ans = 0;
	reu(i, 1, n)
		reu(j, 1, m)
			if(val[i][j] >= 2)
				ans ++;
	cout << ans << endl;
	return 0;
}
