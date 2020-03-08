#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 100;
long long n, t, a[MAXN], s = 0, l = 1, ans = 0;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> t;

	for(int i = 1 ; i<=n ;++i){
		cin >> a[i];
		s += a[i];

		while(s>t)
			s-=a[l++];

		ans = (ans<i-l+1) ? i-l+1 :ans;
	}
	return cout << ans << '\n', 0;
}
