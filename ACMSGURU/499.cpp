#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e5 + 10, maxv = 1e6 + 10;
int built[maxv];
int a[maxn];

void taj(int x){
	int i;
	for(i = 1; i * i < x; i ++)
		if(x % i == 0){
			built[i] ++;
			built[x / i] ++;
		}
	if(i * i == x)
		built[i] ++;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	rep(i, n){
		int t;
		cin >> t;
		taj(t);
	}
	for(int i = maxv; i > 0; i --){
		if(built[i] >= 2){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
