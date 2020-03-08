#include <bits/stdc++.h>
using namespace std;
int ans;
int main(){
	int r, h;   cin >> r >> h;
	ans = h / r * 2;
	h %= r;
	if (h * 2 < r)
		return cout << ans + 1 ,0;
	if (h * 2 < sqrt(3) * r)
		return cout << ans + 2, 0;
	return cout << ans + 3, 0;
}