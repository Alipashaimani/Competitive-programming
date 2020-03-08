#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 200 + 10, maxx = 1e4 + 10;
short int dp[maxn][maxx];
vector<int> v[maxn][maxx];
int a[maxn], n, x;

vector<int> Esht(vector<int> A, vector<int> B){
	vector<int> res;
	for(int p = 0, q = 0; p < A.size() and q < B.size();){
		if(A[p] < B[q])
			p ++;
		else if(A[p] > B[q])
			q ++;
		else{
			res.PB(B[q]);
			p ++, q ++;
		}
	}
	return res;
}

void DP(int i, int j){
	if(dp[i][j] != 0)
		return;
	if(j == 0){
		dp[i][j] = 1;
		return;
	}
	if(i == 0){
		dp[i][j] = -1;
		return;
	}
	if(j < a[i]){
		DP(i - 1, j);
		dp[i][j] = dp[i - 1][j];
		v[i][j] = v[i - 1][j];
		return;
	}
	
	DP(i - 1, j);
	DP(i - 1, j - a[i]);

	if(dp[i - 1][j] > 0 or dp[i - 1][j - a[i]] > 0)
		dp[i][j] = 1;
	else{
		dp[i][j] = -1;
		return;
	}

	if(dp[i - 1][j - a[i]] == -1){
		v[i][j] = v[i - 1][j];
		return;
	}
	if(dp[i - 1][j] == -1){
		v[i][j] = v[i - 1][j - a[i]];
		if(v[i][j].empty() or v[i][j].back() != a[i])
			v[i][j].PB(a[i]);
		return;
	}

	v[i][j] = Esht(v[i - 1][j - a[i]], v[i - 1][j]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	reu(i, 1, n)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	DP(n, x);
	cout << v[n][x].size() << endl;
	rep(i, v[n][x].size())
		cout << v[n][x][i] << ' ';
	cout << endl;
	return 0;
}
