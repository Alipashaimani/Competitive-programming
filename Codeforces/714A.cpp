#include <bits/stdc++.h>
using namespace std ;
long long l1 , r1 , l2 , r2 , k , ans = 0;

int main (){
	cin >> l1 >> r1 >> l2 >> r2 >> k ;
	ans = min(r1, r2) - max (l1, l2) + 1;

	if (k>=max (l1 , l2) && k<= min (r1 , r2))
		ans--;

	if (ans < 0)
		cout << 0 << endl;

	else
		cout << ans <<endl;
}
