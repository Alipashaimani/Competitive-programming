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

const int maxn = 5e4 + 10;
ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
    int n, L = 0, R = 0;
    ll sum = 0;
    cin >> n;
    rep(i, n){
        int x, p;
        cin >> x >> p;
        a[x] += p;
        sum += x * p;
        R += p;
    }
    int ans = 0;
    ll Min = sum;
    for(int i = 0; R != 0; i ++){
        sum += L - R ;
        R -= a[i];
        L += a[i];
        if(sum < Min){
            Min = sum;
            ans = i;
        }
    }
    cout << ans << ".00000" << endl;
	return 0;
}
