#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

int cnt[MAXN], ans[MAXN], a[MAXN], par[MAXN], dp[MAXN];
vector<int> vec;

bool cmp (int x, int y){return a[x] < a[y];}
bool cmp2(int x, int y){return a[x] > a[y];}

int main(){
    int n;  cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    fill(ans, ans + n, 1);

    for (int i = 0; i < n; i++){

        int idx = (int)(lower_bound(vec.begin(), vec.end(), i, cmp) - vec.begin());

        dp[i] = idx;

        if (idx == vec.size())
            vec.push_back(i);
        else
            vec[idx] = i;

        if (idx > 0)
            par[i] = vec[idx - 1];

        else
            par[i] = -1;
    }

    int mx = (int)vec.size(), now = vec.back();

    while (now != -1){
        cnt[now]++;
        now = par[now];
    }

    vec.clear();

    for (int i = n - 1; i >= 0; i--){

        int idx = (int)(lower_bound(vec.begin(), vec.end(), i, cmp2) - vec.begin());

        if (dp[i] + idx + 1 == mx)
            ans[i] = 2;

        if (idx == vec.size())
            vec.push_back(i);
        else
            vec[idx] = i;

        if (idx > 0)
            par[i] = vec[idx - 1];
        else
            par[i] = -1;
    }

    now = vec.back();

    while (now != -1){
        cnt[now]++;
        now = par[now];
    }

    for (int i = 0; i < n; i++)
        cout << (cnt[i] == 2 ? 3 : ans[i]);

    return cout << '\n', 0;
}
