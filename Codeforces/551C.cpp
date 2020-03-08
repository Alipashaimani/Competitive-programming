#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, l, r, mid;
vector <ll> a,v;

bool check(ll s){
    v = a;
    ll t, k;
    k = m-1;
    t = s;
    for (int i = 0; i < n; i++){
        s--;    t--;
        if (!s)
            return 0;

        if (t < 1){
            t = s;
            k --;
        }
        while (v[i] > t){
            v[i] -= t;
            t = s;
            k --;
        }

        t -= v[i];
        if (k<0)
            return 0;

    }
    return (t >= 0);
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        ll x;   cin >> x;
        a.push_back(x);
        if (a[i])
            l = i + 1;
    }

    r = 1e15;
    n = l;

    while (l<r){
        mid = (l + r) /2;

        if (!check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    return cout << (check(l) ? l : r) << endl, 0;
}