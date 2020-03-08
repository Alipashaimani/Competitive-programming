#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e6 + 10;
int n,a[MAXN],c[2][MAXN],ans;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x=0;
	c[0][x]++;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		x ^= a[i];
		ans += c[i+1&1][x];
		c[i+1&1][x]++;
	}
	cout << ans << endl;
}
