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

const int maxn = 101;
bool X[maxn][maxn];
pie a[maxn];
int n, m, w[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	while(m --){
		int p, q;
		cin >> p >> q;
		
		if(!X[q][p])
			a[q].p1 ++;
		X[q][p] = true;
		if(X[p][q]){
			cout << "No solution" << endl;
			return 0;
		}
		
		reu(i, 1, n){
			if(X[i][q]){
				if(!X[i][p])
					a[i].p1 ++;
				X[i][p] = true;
				if(X[p][i]){
					cout << "No solution" << endl;
					return 0;
				}
			}
		}
		reu(i, 1, n){
			if(X[p][i]){
				reu(j, 1, n){
					if(X[j][p]){
						if(!X[j][i])
							a[j].p1 ++;
						X[j][i] = true;
						if(X[i][j]){
							cout << "No solution" << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	/*reu(i, 1, n){
		reu(j, 1, n)
			cerr << X[i][j] << ' ';
		cerr << endl;
	}*/
	reu(i, 1, n)
		a[i].p2 = i;
	sort(a + 1, a + n + 1);
	reu(i, 1, n)
		w[a[i].p2] = i;
	reu(i, 1, n)
		cout << w[i] << ' ';
	cout << endl;
	return 0;
}
