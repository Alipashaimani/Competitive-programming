#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define BP __builtin_popcount
#define endl '\n'

const int maxn = 10;
LL dp[1 << (2 * maxn - 1)];
vector<int> vec[maxn * 2];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if(k > 2 * n - 1){
		cout << 0 << endl;
		return 0;
	}

	//make vec
	for(int i = 0; i < 2 * n - 1; i++){
		int dis = n - 1 - abs(n - 1 - i);
		for(int j = n - 1 - dis; j <= n - 1 + dis; j += 2)
			vec[i + 1].PB(j);
	}

	dp[0] = 1;
	for(int i = 1; i <= 2 * n - 1; i++)
		for(int mask = (1 << (2 * n - 1)) - 1; mask >= 0; mask--)
			for(vector<int>::iterator pos = vec[i].begin(); pos != vec[i].end(); pos++)
				if((mask >> (*pos)) & 1)
					dp[mask] += dp[mask ^ (1 << (*pos))];//, cout << mask << ' ' << (*pos) << ' ' << (mask ^ (1 << (*pos))) << endl;

	LL ans = 0;
	for(int mask = 0; mask < (1 << (2 * n - 1)); mask++)
		if(BP(mask) == k)
			ans += dp[mask];
	cout << ans << endl;
	return 0;
}
