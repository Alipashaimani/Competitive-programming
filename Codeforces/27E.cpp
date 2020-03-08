#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans = 1, cnt;
int p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

void gen (int level, int minc, long long div, long long number) {
    if (level == 0) {
        if (div == n)
            ans = number;
        return;
    }
    gen (level - 1, minc, div, number);
    while (div < n) {
        for (int i = 0; i < level; i++){
            div = div / minc * (minc + 1);
            number *= p[i];
        }
        if (number > ans)
            break;
        gen (level - 1, minc + 1, div, number);
        minc++;
    }
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < 18; i++) ans *= p[i];
    gen (18, 1, 1, 1);
    cout << ans << endl;
    return 0;
}
