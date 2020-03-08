#include <bits/stdc++.h>
using namespace std;

#define show(x) cerr << #x <<  ": " << x << '\n';

const int MAXN = 3e5 + 10;

vector<int>cnt[MAXN];
int arr[MAXN];

bool check(int b, int e, int can) {
    if ((lower_bound(cnt[can].begin(), cnt[can].end(), e) - lower_bound(cnt[can].begin(), cnt[can].end(), b)) > (e - b) / 2)
        return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c;  cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]].push_back(i);
    }
    int q;  cin >> q;
    while (q--) {
        int l, r;   cin >> l >> r;  l--;
        int b = 0;
        bool flag = false;
        while(b++ < 50){
            int x = arr[l + rand() % (r - l + 1)];
            if (check(l, r, x)) {
                cout << "yes " << x << '\n';
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "no \n";
    }
}
