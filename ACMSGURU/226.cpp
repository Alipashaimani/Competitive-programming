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

const int maxn = 2e2 + 50;
int n, m;
bool v[maxn][maxn][4];
int dp[maxn][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	reu(i, 1, n){
		dp[i][1] = 1e9;
		dp[i][2] = 1e9;
		dp[i][3] = 1e9;
	}
	reu(i, 1, m){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi][se][th] = true;
	}
	cerr << 'H' << endl;
	set<int> s[4], p[4];
	s[1].insert(1);
	s[2].insert(1);
	s[3].insert(1);
	dp[1][1] = 0;
	dp[1][2] = 0;
	dp[1][3] = 0;
	while(s[1].size() + s[2].size() + s[3].size()){
		cerr << s[1].size() << s[2].size() << s[3].size() << endl;
		while(s[1].size()){
			int x = *s[1].begin();
			s[1].erase(s[1].begin());
			reu(i, 1, n){
				if(v[x][i][2]){
					if(dp[i][2] == 1e9){
						dp[i][2] = dp[x][1] + 1;
						p[2].insert(i);
					}
				}
				if(v[x][i][3]){
					if(dp[i][3] == 1e9){
						dp[i][3] = dp[x][1] + 1;
						p[3].insert(i);
					}
				}
			}
		}
		while(s[2].size()){
			int x = *s[2].begin();
			s[2].erase(s[2].begin());
			reu(i, 1, n){
				if(v[x][i][1]){
					if(dp[i][1] == 1e9){
						dp[i][1] = dp[x][2] + 1;
						p[1].insert(i);
					}
				}
				if(v[x][i][3]){
					if(dp[i][3] == 1e9){
						dp[i][3] = dp[x][2] + 1;
						p[3].insert(i);
					}
				}
			}
		}
		while(s[3].size()){
			int x = *s[3].begin();
			s[3].erase(s[3].begin());
			reu(i, 1, n){
				if(v[x][i][2]){
					if(dp[i][2] == 1e9){
						dp[i][2] = dp[x][3] + 1;
						p[2].insert(i);
					}
				}
				if(v[x][i][1]){
					if(dp[i][1] == 1e9){
						dp[i][1] = dp[x][3] + 1;
						p[1].insert(i);
					}
				}
			}
		}
		s[1] = p[1];
		s[2] = p[2];
		s[3] = p[3];
		p[1].clear();
		p[2].clear();
		p[3].clear();
	}
	cerr << dp[n][1] << ' ' << dp[n][2] << ' ' << dp[n][3] << endl;
	if(min(dp[n][1], min(dp[n][2], dp[n][3])) == 1e9)
		cout << -1 << endl;
	else
		cout << min(dp[n][1], min(dp[n][2], dp[n][3])) << endl;
	return 0;
}
