#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

int x, y;
int p[(int)1e7 + 100];

void input(){
	cin >> x >> y;
	int t = __gcd(x, y);
	x /= t;
	y /= t;
	x %= y;
}

int main(){
	ios_base::sync_with_stdio(false);
	input();
	if(x == 0){
		cout << "0 0" << endl;
		return 0;
	}
	int a = 0, b;
	for(int i = 1; 1; i ++){
		//cerr << x << ' ';
		x *= 10;
		if(x == 0){
			cout << a << " 0" << endl;
			return 0;
		}
		if(p[x]){
			b = i - p[x];
			break;
		}
		p[x] = i;
		a ++;
		x %= y;
		//cerr << x << endl;
	}
	cout << a - b << ' ' << b << endl;
	return 0;
}
