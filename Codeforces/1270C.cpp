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

		ll sum = 0, Xor = 0;

		rep(i , 0 , n) {
			cin >> arr[i];
			sum += arr[i];
			Xor ^= arr[i];
		}

		ll add = 1ll << 55;
		if (sum & 1) add++;
		sum += add;
		Xor ^= add;
		Xor <<= 1;
		Xor = (Xor - sum) >> 1;
		cout << "3\n" << add << ' ' << Xor << ' ' << Xor << '\n';

	}

  return 0;
}
