#include <bits/stdc++.h>
using namespace std;

#define show(x) cerr << #x << " =  " << x << endl;
typedef long double dd;

const int MAXN = 1e5 + 7;
const dd EPS = 1e-9;
int n, k, h, m[MAXN], s[MAXN];

vector<int> ans;
vector<pair< pair<int, int>, int> > v;

bool check(dd x) {
    ans.clear();
    int cnt = k;
    for (int i = n-1; ~i && cnt; --i){
        if (cnt * h / dd(s[v[i].second]) < x + EPS){
            ans.push_back (v[i].second);
            cnt--;
        }
    }
    if (cnt)
        return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k >> h;
    for (int i = 0; i < n; i++)
        cin >> m[i];

    for (int i = 0; i < n; i++){
        cin >> s[i];
        v.push_back({{m[i], s[i]}, i});
    }

    sort(v.begin(), v.end());

    dd l = 0, r = 1e9 + 7;
    for (int i = 0; i < 100; i++){
        dd mid = (l+r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    check(r);
    for (int i = ans.size()-1; ~i; --i)
        cout << ans[i]+1 << " ";
}