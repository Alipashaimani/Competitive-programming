#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int bit[MAXN + 100], ans[MAXN], _pos[MAXN];
vector<pair<int, int> > _query[MAXN];
vector<int> d[MAXN];


void upd(int id){
    for (; id <= MAXN; id += id & (-id))
        bit[id]++;
    return;
}

int get(int id){
    int now = 0;
    for (; id > 0; id = id & (id - 1))
        now += bit[id];
    return now;
}

int main(){
    ios::sync_with_stdio(0);

    int n,q;    cin >> n >> q;
    for (int i = 0; i < n; i++){
        int x;  cin >> x;
        _pos[x] = i + 1;
    }

    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        _query[y].push_back({ i , x });
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            d[max(_pos[i], _pos[j])].push_back(min(_pos[i], _pos[j]));

    for (int i = 1; i <= n; i++){
        for (auto j : d[i])
            upd(j);

        for (auto j : _query[i])
            ans[j.first] = get(i) - get(j.second - 1);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}