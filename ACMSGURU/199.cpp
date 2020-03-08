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

const int maxn = 1e5 + 10;
pie dp[maxn];
pie pd[maxn];
pie par[maxn];
pair<pie, int> a[maxn];
int Size = 0;

int main(){
	int n;
	scanf("%d", &n);
	rep(i, n){
		scanf("%d%d", &(a[i].p1.p1), &(a[i].p1.p2));
		a[i].p2 = i + 1;
	}
	sort(a, a + n);
	rep(i, n){
		pie *it = lower_bound(dp, dp + Size, MP(a[i].p1.p2, -1));
		if(it == dp + Size){
			if(Size > 0){
				if(a[dp[Size - 1].p2].p1.p1 != a[i].p1.p1){
					par[i].p1 = dp[Size - 1].p2;
					dp[Size] = MP(a[i].p1.p2, i);
					Size ++;
				}
				else if(pd[Size - 1].p1 != 0 and pd[Size - 1].p1 < a[i].p1.p2 and a[pd[Size - 1].p2].p1.p1 != a[i].p1.p1){
					par[i].p1 = pd[Size - 1].p2;
					dp[Size] = MP(a[i].p1.p2, i);
					Size ++;
				}
			}
			else{
				dp[Size] = MP(a[i].p1.p2, i);
				Size ++;
			}
			//cerr << Size << ' ' << dp[Size - 1].p2 << endl;
			continue;
		}
		if(it -> p1 == a[i].p1.p2)
			continue;
		if(it == dp){
			pd[0] = MP(dp[0].p1, dp[0].p2);
			dp[0] = MP(a[i].p1.p2, i);
			continue;
		}
		if(a[(it - 1)->p2].p1.p1 != a[i].p1.p1){
			(it - dp + pd)->p1 = (it)->p1;
			(it - dp + pd)->p2 = (it)->p2;
			(it)->p1 = a[i].p1.p2;
			(it)->p2 = i;
			par[i].p1 = (it - 1)->p2;
		}
		else if((it - dp + pd - 1)->p1 != 0 and (it - dp + pd - 1)->p1 < a[i].p1.p2 and a[(it - dp + pd - 1)->p2].p1.p1 != a[i].p1.p1){
			(it - dp + pd)->p1 = (it)->p1;
			(it - dp + pd)->p2 = (it)->p2;
			(it)->p1 = a[i].p1.p2;
			(it)->p2 = i;
			par[i].p1 = (it - dp + pd - 1)->p2;
		}
	}
	printf("%d\n", Size);
	int root = dp[Size - 1].p2;
	while(Size--){
		printf("%d ", a[root].p2);
		root = par[root].p1;
	}
	printf("\n");
	return 0;
}
