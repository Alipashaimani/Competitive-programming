#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

pair<pair<int, int>, int> a[MAXN];
vector<pair<pair<int, int> ,int> > pk;
vector<int> ans;
bool mark[MAXN];

int main(){

    int n, p, k;    cin >> n >> p >> k;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i].first.second >> a[i].first.first;
        a[i].second = i;
        a[i].first.second *= -1;
    }

    sort(a, a+n, greater<pair<pair<int, int>,int> > ());

    for (int i = 0; i < n; i++)
        a[i].first.second *= -1;

    for (int i = 0; i < n - (p-k); i++)
        pk.push_back({{a[i].first.second, -i}, a[i].second});

    sort(pk.begin(), pk.end(), greater<pair<pair<int,int>, int > > ());

    for (int i = 0; i < k ; i++){
        ans.push_back(pk[i].second+1);
        mark[pk[i].second] = 1;
    }

    int idx = -1;
    for (int i = 0; i < n; i++)
        if(mark[a[i].second])
            idx = i;

    for (int i = idx + 1; i < n; i++)
        if(ans.size() < p)
            ans.push_back(a[i].second+1);

    for (int i = 0; i < p; i++)
        cout << ans[i] << ' ';

    return 0;
}
