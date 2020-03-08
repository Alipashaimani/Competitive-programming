#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	int n,v; cin >> n >> v;
	v = min(v, n-1);
	int ans = v;
	for (int i = 0; i < n-1-v; i++)
		ans += i+2;
	cout << ans << endl;
}
