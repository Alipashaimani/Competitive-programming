#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int seg[MAXN * 4];
int n, q;

void update (int l, int r , int id, int val, int idx, bool m) {
    if (r - l == 1) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (idx < mid)
        update(l, mid, id << 1, val, idx, !m);
    else
        update(mid, r, id << 1 | 1, val, idx, !m);
    if (m)
        seg[id] = seg[id << 1] | seg [id << 1 | 1];
    else
        seg[id] = seg[id << 1] ^ seg[id << 1 | 1];
}


int main () {
    cin >> n >> q;
    for (int i = 0, x; i < 1 << n; ++i) {
        cin >> x;
        update(0, 1 << n, 1, x, i, n&1);
    }
    while (q--) {
        int idx, val; cin >> idx >> val;    --idx;
        update(0, 1 << n, 1, val, idx, n&1);
        cout << seg[1] << '\n';
    }
    return 0;
}