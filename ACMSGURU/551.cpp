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

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
	int n, t1, t2, f;
	cin >> n >> t1 >> t2;
	int lcm = t1 * t2 / __gcd(t1, t2);
	int g = lcm / t1 + lcm / t2;
	if(n % g == 0)
		cout << n << ' ';
	else
		cout << n + 1 << ' ';
	f += lcm * (n / g);
	n %= g;
	int t = 0;
	int c = 0;
	int x, y;
	while(c < n){
		x = t1 - (t % t1);
		y = t2 - (t % t2);
		if(x < y){
			t += x;
			c ++;
		}
		else if(x > y){
			t += y;
			c ++;
		}
		else{
			t += x;
			c += 2;
		}
	}
	if(t % t1 == 0 && t % t2 != 0)
		cout << f + t + (t2 - (t % t2)) << endl;
	else if(t % t1 != 0 && t % t2 == 0)
		cout << f + t + (t1 - (t % t1)) << endl;
	else
		cout << f + t << endl;
	return 0;
}
