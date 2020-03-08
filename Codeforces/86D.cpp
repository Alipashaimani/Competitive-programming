#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 100;
int n, a[N], q, k;
long long ans;
vector<array<int, 3>> queries;
long long cnt[N];

void add(int x){
    ans -= cnt[x]*cnt[x]*x;
    cnt[x]++;
    ans += cnt[x]*cnt[x]*x;
}
void del(int x){
    ans -= cnt[x]*cnt[x]*x;
    cnt[x]--;
    ans += cnt[x]*cnt[x]*x;
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
    cin >> n >> q;;
    k = int(sqrt(n)) + 1;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (q--) {
        int i, j;
        cin >> i >> j;
        queries.push_back({i - 1, j - 1, (int)queries.size()});
    }


    vector<long long> p(queries.size());

    sort(queries.begin(), queries.end(), [] (array<int, 3> a, array<int, 3> b) {
        if (a[0] / k != b[0] / k)
            return a[0] < b[0];
        return a[1] < b[1];
    });


    cnt[a[0]] = 1;
    int l = 0, r = 0;
    ans = a[0];

    for (int i = 0; i < queries.size(); ++i) {
        while (l < queries[i][0])
            del(a[l++]);
        while (l > queries[i][0])
            add(a[--l]);
        while (r < queries[i][1])
            add(a[++r]);
        while (r > queries[i][1])
            del(a[r--]);
        p[queries[i][2]] = ans;
    }
    for (auto i: p)
        cout << i << '\n';
}