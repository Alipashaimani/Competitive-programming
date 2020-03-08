#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 100;

pair<int, int> a[MAXN];

int main(){
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    int ans = 0;
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(min(a[i].first, a[i].second) >= ans)
            ans = min(a[i].first, a[i].second);
        else
            ans = max(a[i].first, a[i].second);
    }
    return cout << ans << '\n', 0;
}