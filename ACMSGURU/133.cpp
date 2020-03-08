#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
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
    int ans = 0;
    pie a[n];
    bool mark[n];
    memset(mark, true, sizeof mark);
    rep(i, n)
        cin >> a[i].p1 >> a[i].p2;
    sort(a, a + n);
    FOR(i, 0, n-1){
        if(mark[i]){
            FOR(j, i + 1, n-1){
                if(a[j].p1 > a[i].p2)
                    break;
                if(mark[j] && a[j].p1 > a[i].p1 && a[j].p2 < a[i].p2){
                    mark[j] = false;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}
