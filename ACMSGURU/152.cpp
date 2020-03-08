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
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
        a[i] *= 100;
    }
    vector <pie> v, w;
    ll s = 0, t = 0;
    rep(i, n){
        if(a[i] % sum == 0){
            s += a[i] / sum;
            v.pb(mp(a[i]/sum, i));
        }
        else{
            t += a[i] / sum;
            w.pb(mp(a[i]/sum, i));
        }
    }
    rep(i, 100 - s - t)
        w[i].p1++;
    int p = 0, q = 0;
    while(p < v.size() || q < w.size()){
        if(p == v.size())
            cout << w[q++].p1 << ' ';
        else if(q == w.size())
            cout << v[p++].p1 << ' ';
        else if(v[p].p2 < w[q].p2)
            cout << v[p++].p1 << ' ';
        else
            cout << w[q++].p1 << ' ';
    }
	return 0;
}
