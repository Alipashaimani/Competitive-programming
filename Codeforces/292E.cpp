#include <bits/stdc++.h>
using namespace std;

#define bug(x) cerr << #x << " " << x << '\n';

const int MAXN = 1e5 + 10;
int lazy[4 * MAXN], n, m, arr[MAXN], arr2[MAXN];

void shift(int b, int e, int id) {
    if (~lazy[id]){
        int mid = (b + e) >> 1;
        lazy[id << 1] = lazy[id];
        lazy[id << 1 | 1] = lazy[id] + mid - b;
        lazy[id] = -1;
    }
}

int query(int b, int e, int x, int id) {
    if (e - b == 1) {
        if (!~lazy[id])
            return arr2[x];
        return arr[lazy[id]];
    }
    shift(b, e, id);
    int mid = (b + e) >> 1;
    if (x >= mid)
        return query(mid, e, x, id << 1 | 1);
    return query(b, mid, x, id << 1);
}

void upd(int l, int r, int b, int e, int x, int id) {
    if (r <= b or e <= l)
        return;
    if (l <= b and e <= r) {
        lazy[id] = x;
        return;
    }

    shift(b, e, id);

    int mid = (b + e) >> 1;

    if (mid > l) {
        upd(l, r, b, mid, x, id << 1);
        x += mid - l;
    }
    if (mid < r)
        upd(max(l, mid), r, mid, e, x, id << 1 | 1);

    return;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
        cin >> arr2[i];

    memset(lazy, -1, sizeof(lazy));

    while (m--) {
        int a, b;
        cin >> a >> b;   b--;
        if (a - 1)
            cout << query(0, n, b, 1) << '\n';
        else {
            int c, d;
            cin >> c >> d;  c--;
            upd(c, c + d,0, n, b, 1);
        }

    }
    return 0;
}