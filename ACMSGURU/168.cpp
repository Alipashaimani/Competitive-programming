#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)t; (i)++)
#define reu(i, s, e) for(ll (i) = (ll)s; (i) <= (ll)e; (i)++)
#define rer(i, s, e) for(ll (i) = (ll)s; (i) < (ll)e; (i)++)
#define mset(arr, val) memset(arr, val, sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e3 + 100;
ll a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, n)
        rep(j, m)
            scanf("%lld", &(a[i][j]));
    for(int i = n - 2; i>= 0; i--)
        a[i][m - 1] = min(a[i][m - 1], a[i + 1][m - 1]);
    for(int j = m - 2; j >= 0; j--){
        if(n >= 2 && a[n - 2][j + 1] < a[n - 1][j])
            a[n - 1][j] = a[n - 2][j + 1];
        for(int i = n - 2; i > 0; i--)
            a[i][j] = min(a[i][j], min(a[i + 1][j], a[i - 1][j + 1]));
        if(n > 2)
            a[0][j] = min(a[0][j], a[1][j]);
        a[0][j] = min(a[0][j], a[0][j + 1]);
    }

    rep(i, n){
        rep(j, m)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
	return 0;
}
