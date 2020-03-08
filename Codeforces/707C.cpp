#include<bits/stdc++.h>
using namespace std;
int main() {
	long long a;
	cin >> a;
	if (a < 3) {
		cout << -1 ;
		return 0;
	}
	else if (a * a % 4) {
		cout << (a * a / 2) << " " << ((a * a / 2) + 1);
		return 0;
	}
	else
		cout << ((a * a / 4) - 1) << " " << ((a * a / 4 ) + 1);

	return 0;
}