#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
long long t[MAXN], n, ans, k;
int main(){

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];

    sort(t, t + n);

    for (int i = 0; i < n; i++)
        if (t[i] >= k) {
            ++ans;
            k += t[i];
        }

    cout << ans << '\n';
    return 0;
}
