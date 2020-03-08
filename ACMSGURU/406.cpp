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
    set <int> d[n];
    vector <int> v[n];
    rep(i, n){
        int t;
        cin >> t;
        v[i].pb(t);
        rep(j, t){
            int tt;
            cin >> tt;
            d[i].insert(tt);
            v[i].pb(tt);
        }
    }
    rep(i, m){
        bool mark[n];
        mset(mark, true);
        string s;
        int t, k;
        cin >> k;
        rep(ii, k){
            cin >> t;
            if(t > 0){
                rep(j, n)
                    if(d[j].find(t) == d[j].end())
                        mark[j] = false;
            }
            else{
                t *= -1;
                rep(j, n)
                    if(d[j].find(t) != d[j].end())
                        mark[j] = false;
            }
        }
        int cnt = 0;
        rep(j, n)
            if(mark[j])
                cnt++;
        cout << cnt << endl;
        rep(j, n){
            if(mark[j]){
                rep(k, v[j].size())
                    cout << v[j][k] << ' ';
                cout << endl;
            }
        }
    }
	return 0;
}
