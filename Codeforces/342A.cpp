#include <bits/stdc++.h>
using namespace std;

int cnt[100];

int main(){
    int n;  cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    if (cnt[2] < cnt[4] or cnt[5] or cnt[7] or cnt[1] != cnt[2] + cnt[3] or cnt[2] + cnt[3] != cnt[4] + cnt[6])
        return cout << "-1\n",0;
    cnt[2] -= cnt[4];
    while (cnt[2]--)
        cout << "1 2 6\n";
    while (cnt[3]--)
        cout << "1 3 6\n";
    while (cnt[4]--)
        cout << "1 2 4\n";
    return 0;
}
