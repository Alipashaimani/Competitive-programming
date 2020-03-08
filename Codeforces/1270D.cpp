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

ll A[N], B[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	rep(i , 0 , k + 1) {
		cout << "?";
		rep(j , 0 , k + 1)
			if (i != j) cout << ' ' << j + 1;
		cout << endl;
		cin >> A[i] >> B[i];
		A[i]--;
	}

	int mid = A[k];

	bool smaller = false;
	if (B[mid] < B[k]) smaller = true;

	int res = 0;
	rep(i , 0 , k) {
		if (i == mid) continue;
		if (A[i] == mid) {
			if (smaller) res++;
		}
		else if (B[i] > B[k]) res++;
	}

	cout << "! " << res + 1 << endl;


	return 0;
}
