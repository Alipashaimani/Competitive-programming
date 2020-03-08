#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
long long seg[4 * MAXN][22], lazy[4 * MAXN];
int arr[MAXN];

void build(int b, int e, int id) {
    if (e - b == 1) {
        int x = arr[b];
        for (; x; x -= (x & -x))
            ++seg[id][__builtin_ctz(x)];
        return;
    }
    int mid = (e + b) >> 1;

    build(b, mid, id << 1);
    build(mid, e, id << 1 | 1);

    for (int i = 0; i <= 20; ++i)
        seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
}

void shift(int b, int e, int id) {
    lazy[id << 1] ^= lazy[id];
    lazy[id << 1 | 1] ^= lazy[id];

    int mid = (b + e) >> 1;
    int x = lazy[id];
    for (; x; x -= (x & -x)) {
        seg[id << 1][__builtin_ctz(x)] = (mid - b) - seg[id << 1][__builtin_ctz(x)];
        seg[id << 1 | 1][__builtin_ctz(x)] = (e - mid) - seg[id << 1 | 1][__builtin_ctz(x)];
    }

    lazy[id] = 0;
}

void upd(int l, int r, int b, int e, int id, int x) {
    if (r <= b or e <= l)
        return;
    if (l <= b and e <= r) {
        lazy[id] ^= x;
        for (; x; x -= (x & -x))
            seg[id][__builtin_ctz(x)] = (e - b) - seg[id][__builtin_ctz(x)];

        return;
    }
    shift(b, e, id);
    int mid = (b + e) >> 1;
    upd(l, r, b, mid, id << 1 , x);
    upd(l, r, mid, e, id << 1 | 1 , x);

    for (int i = 0; i <= 20; ++i)
        seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
}

long long query(int l, int r,int b, int e, int id) {
    if (r <= b or e <= l)
        return 0;

    if (l <= b and e <= r) {
        long long ans = 0;
        for (long long i = 0; i <= 20; ++i)
            ans += seg[id][i] * (1 << i);
        return ans;
    }
    shift(b, e, id);

    int mid = (b + e) >> 1;

    return query (l, r, b, mid, id << 1) +
           query (l, r, mid, e, id << 1 | 1);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;   cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    build(0, n, 1);

    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;  b--;
        if (a == 1)
            cout << query(b, c, 0, n, 1) << '\n';
        else {
            int x;  cin >> x;
            upd(b, c, 0, n, 1, x);
        }
    }
    return 0;
}