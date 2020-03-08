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

const int maxn = 2e5 + 10;
pair<pie, int> a[maxn];
pie dp[maxn];
int ans, d;
int n;
pie x;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> d;
	rep(i, n){
		cin >> a[i].p1.p1 >> a[i].p1.p2;
		a[i].p2 = i + 1;
	}
	sort(a, a + n);
	dp[n - 1] = MP(a[n - 1].p1.p2, a[n - 1].p2);
	for(int i = n - 2; i >= 0; i--)
		dp[i] = max(dp[i + 1], MP(a[i].p1.p2, a[i].p2));
	for(int p = 0, q = 0; p < n; p ++){
		while(a[q].p1.p1 < a[p].p1.p1 + d and q < n)
			q++;
		if(q == n)
			break;
		if(a[p].p1.p2 + dp[q].p1 > ans){
			ans = a[p].p1.p2 + dp[q].p1;
			x.p1 = a[p].p2;
			x.p2 = dp[q].p2;
		}
	}
	if(x.p1 == 0 and x.p2 == 0)
		cout << "-1 -1" << endl;
	else
		cout << x.p1 << ' ' << x.p2 << endl;
	return 0;
}
