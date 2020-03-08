#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6 + 10;

map <int, int> f1, f2, cnt;
int n, a[MAXN], fw[MAXN];
long long ans = 0;

void update (int i){
    for (; i <= n; i += i&(-i))
        ++fw[i];
}

int query (int i) {
    int x = 0;
    for (--i; ~i+1; i -= i&(-i))
        x += fw[i];
    return x;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i],    f1[i] = ++cnt[a[i]];

    for(int i = 1; i <= n; ++i)
        f2[i] = cnt[a[i]]--;

    for(int i = n; ~i+1; --i)
        ans += query(f1[i]),    update(f2[i]);

    cout << ans << endl;
}