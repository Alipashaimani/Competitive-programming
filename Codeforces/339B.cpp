#include <bits/stdc++.h>
using namespace std;
const long long  MAXN = 1e5 + 100;
long long m,n,a[MAXN],ans,h = 1;
int main(){
	cin >> m >> n;
	for ( long long  i = 0 ; i < n ; i++){
		cin >> a[i];
		if ( a[i] == h)
			continue ;

		if ( a[i] > h )
			ans += a[i]-h;
		else
			ans += ( m - h ) + a[i];

			h = a[i];
	}
	cout << ans;
}
