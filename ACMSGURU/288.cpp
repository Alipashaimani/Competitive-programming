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

const int maxn = 2e3 + 10;
int P[maxn][maxn];

int rp(int x, int n){
	if(x <= 0)
		return x + n;
	if(x > n)
		return x - n;
	return x;
}

void F(int s, int n){
	//cout << n << endl;
	if(n == 2){
		P[s][s + 1] = (P[s + 1][s] = 1);
		return;
	}
	if(n & 1){
		reu(i, 1, n)
			reu(j, 1, n)
				P[rp(i - j, n) + s - 1][rp(i + j, n) + s - 1] = i;
		rep(i, n)
			P[s + i][s + i] = 0;
		return;
	}
	F(s, n / 2);
	F(s + n / 2, n / 2);
	if(n % 4 == 0){
		int ss = s + n / 2;
		rer(i, -1, n / 2){
			rep(j, n / 2){
				P[i + s][n / 2 - j + ss - 1] = rp(i + j, n / 2) + n / 2 - 1;
				P[n / 2 - j + ss - 1][i + s] = rp(i + j, n / 2) + n / 2 - 1;
			}
		}
		return;
	}
	int ss = s + n / 2;
	rep(i, n / 2){
		P[i + s][i + ss] = i + 1;
		P[i + ss][i + s] = i + 1;
	}
	reu(i, 1, n / 2){
		P[s + i - 1][ss + i] = n / 2 + 1;
		P[ss + i][s + i - 1] = n / 2 + 1;
		if(i == n / 2){
			P[s + i - 1][ss] = n / 2 + 1;
			P[ss][s + i - 1] = n / 2 + 1;
		}
		//cout << s + i - 1 << ' ' << ss + i << endl;
		rer(j, 2, n / 2){
			int x = P[s + i - 1][rp(i + j - 1, n / 2) + ss - 1] + 1;
			P[s + i - 1][rp(i + j, n / 2) + ss - 1] = x;
			P[rp(i + j, n / 2) + ss - 1][s + i - 1] = x;
		}
	}
}

int main(){
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 1){
		cout << 0 << endl;
		cout << 0 << endl;
		return 0;
	}
	if(n & 1)
		cout << n << endl;
	else
		cout << n - 1 << endl;
	F(1, n);
	reu(i, 1, n){
		reu(j, 1, n)
			printf("%d ", P[i][j]);
		printf("\n");
	}
	return 0;
}
