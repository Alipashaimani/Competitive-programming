#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;

#define EPS (-(1e-10))

LD Mod(LL x, LD y){
	LL yy = y * 10000;
	x %= yy;
	LD xx = x;
	while(xx >= EPS)
		xx -= y;
	xx += y;
	return xx;
}

LL ABS(LL x){
	return (x < 0) ? -x : +x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n, pos = 0;
	LD l;
	cin >> l >> n;
	for(int i = 0; i < n; i++){
		LL t, v;
		cin >> t >> v;
		pos += t * v;
	}
	pos = ABS(pos);
	cout.precision(4);
	cout << fixed << min(Mod(pos, l), l - Mod(pos, l)) << endl;
	return 0;
}
