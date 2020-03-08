#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;

vector<int> seg[4 * MAXN];
pair<int,int> ox[MAXN];

void change(int idx, int val, int x, int b, int e){
    seg[x].push_back(val);

    if (e - b == 1)
        return;

    int mid = (b + e) >> 1;

    if (idx < mid)
        change(idx, val, x << 1, b, mid);
    else
        change(idx, val, x << 1 | 1, mid, e);
}

int query(int idx, int l, int r, int b = 0, int e = MAXN, int x = 1){
    if (r <= b or e <= l)
        return 0;
    if (l <= b and e <= r)
        return seg[x].size() - (lower_bound(seg[x].begin(), seg[x].end(), idx) - seg[x].begin());
    int mid = (b + e) >> 1;
    return  query(idx, l, r, b, mid, x << 1) + query(idx, l, r, mid, e, x << 1 | 1);
}

int main(){
    ios::sync_with_stdio(0);

    int n, m;   cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> ox[i].first >> ox[i].second;

    sort(ox, ox + n);

    for (int i = 0; i < n; ++i)
        change(i, ox[i].second, 1, 0, MAXN);

    for (int i = 0; i < 4 * MAXN; ++i)
        sort(seg[i].begin(), seg[i].end());

    for (int i = 0; i < m; ++i){
        int cnt;    cin >> cnt;
        int ans = 0, _past = -1;
        for (int j = 0; j < cnt; ++j){
            int p;    cin >> p;
            int l = upper_bound(ox, ox + n, make_pair(_past, MAXN)) - ox;
            int r = upper_bound(ox, ox + n, make_pair(p, MAXN)) - ox;
            ans += query(p, l, r, 0, MAXN, 1);
            _past = p;
        }
        cout << ans << "\n";
    }
    return 0;
}
