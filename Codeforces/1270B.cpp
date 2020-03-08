#ifdef __clang__
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define rep(i , j , k) for (int i = j; i < (int)k; i++)
typedef long long ll;

const int N = 1e6 + 10;
ll arr[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		rep(i , 0 , n) cin >> arr[i];
		bool flag = false;
		rep(i , 1 , n) {
			if (abs(arr[i] - arr[i - 1]) >= 2) {
				cout << "YES\n" << i << ' ' << i + 1 << '\n';
				flag = true;
				break;

			}
		}
		if (!flag) cout << "NO\n";

	}

  return 0;
}
