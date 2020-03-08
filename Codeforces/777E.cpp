#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 1000;

ll fw[MAXN], ans, n;
set<ll> sz;
map<ll, ll> num;
vector<pair<ll,pair<ll,ll> > >d;

ll query(ll i){
    i--;
    ll x = 0;
    for (;i > 0; i-=i&-i)
        x  = max(x ,fw[i]);
    return x;
}
void upd(ll i, ll x){
    for (;i <= MAXN ; i+=i&-i)
        fw[i] = max(fw[i], x);
    return;
}
int main(){

    cin >> n;
    for (int i = 0 ; i < n ; i++){
        ll a, b, h;   cin >> a >> b >> h;
        sz.insert(a);   sz.insert(b);
        d.push_back({b, {a, h}});
    }
    ll cnt = 0;
    for (auto i : sz)
        num[i] = ++cnt;


    sort(d.begin(), d.end(), greater<pair<ll,pair<ll,ll> > > ());

    for(int i = 0; i < n; i++){
        ans = max(ans, query(num[d[i].first]) + d[i].second.second);
        upd(num[d[i].second.first],query(num[d[i].first]) + d[i].second.second);
    }
    return cout << ans << '\n' ,0;
}
