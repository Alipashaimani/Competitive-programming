#ifdef __clang__
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		ll A = -1, B = -1;
		for (int i = 0; i < k1; i++) {
			ll local;
			cin >> local;
			A = max(A , local);
		}
		for (int i = 0; i < k2; i++) {
			ll local;
			cin >> local;
			B = max(B , local);
		}
		string res = "YES\n";
		if (B > A) res = "NO\n";
		cout << res;

	}

  return 0;
}
