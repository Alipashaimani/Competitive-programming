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

int main(){
	ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    ll d[n + 1];
    mset(d, 0);
    rep(i, m){
        int fi, se;
        cin >> fi >> se;
        d[fi]++;
        d[se]++;
    }
    ll ans = 0;
    reu(i, 1, n)
        ans += d[i] * d[i];
    cout << ans << endl;
	return 0;
}
