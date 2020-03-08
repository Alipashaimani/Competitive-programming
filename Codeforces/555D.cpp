#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1000;
int n,q;
int point[MAXN];
map<int,int> rx, lx;

int ans(int p, int l) {

    if (n == 1)
        return 1;

    bool dir = false;
    auto it = rx.upper_bound(point[p]+l);   it--;
    int b = it->second;
    l -= point[b] - point[p];

    while (1) {
        if (dir)
            it = rx.upper_bound(point[b]+l);
        else
            it = lx.upper_bound(-point[b]+l);
        it--;
        int c = it -> second;

        if (c == b)
            return b;

        if (c == p) {
            int t = abs(point[p] - point[b]);
            int d = l / t;
            l %= t;
            if (d & 1) {
                swap(p,b);
                dir ^= 1;
            }
        }
        else {
            l -= abs(point[c]-point[b]);
            p = b; b = c;
            dir ^= 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n;i++) {
        cin >> point[i];
        rx.insert({ point[i],i});
        lx.insert({-point[i],i});
    }

    while(q--){
        int a,l;    cin >> a >> l;
        cout << ans(a,l) << "\n";
    }

    return 0;
}