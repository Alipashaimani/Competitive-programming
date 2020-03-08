#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 1e5 + 100;
ll seg[4 * MAXN];
pair<pair<ll, ll>, ll > qu[MAXN];

void shift(ll id){
    seg[id << 1] = seg[id] | seg[id << 1];
    seg[id << 1 | 1] = seg[id] | seg[id << 1 | 1];
}

void upd(ll l, ll r, ll b, ll e, ll id, ll k){
    if (r <= b or e <= l)
        return;
    if (l <= b and e <= r){
        seg[id] = seg[id] | k;
        //        shift(id);
        return;
    }
    ll mid = (b + e) >> 1;
    shift(id);
    upd(l, r, b, mid, id << 1, k);
    upd(l, r, mid, e, id << 1 | 1, k);
    return;
}

ll check(ll l, ll r, ll b, ll e, ll id){
    if (r <= b or e <= l)
        return (1<<31)-1;
    if (l <= b and e <= r)
        return seg[id];
    shift(id);
    ll mid = (b + e) >> 1;
    return check(l, r, b, mid, id << 1) & check(l, r, mid, e, id << 1 | 1);
}
void ans(ll b, ll e, ll id){
    if (e - b == 1){
        cout << seg[id] << " ";
        return;
    }
    shift(id);
    ll mid = (b + e) >> 1;
    ans (b, mid, id << 1);
    ans(mid, e, id << 1 | 1);
    return;
}

int main(){
    ll n, q;   cin >> n >> q;

    for (ll i = 0 ; i < q; i++){
        ll l, r, k;  cin >> l >> r >> k;   l--;
        upd(l, r, 0, n, 1, k);
        qu[i] = {{l,r},k};
    }
    for (ll i = 0 ; i < q; i++){
        if (qu[i].second != check(qu[i].first.first, qu[i].first.second,0, n, 1)){
            return cout << "NO" << endl, 0;
        }
    }
    cout << "YES\n";
    ans(0,n,1);
    return 0;
}