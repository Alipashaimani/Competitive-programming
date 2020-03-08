#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int cntl, cntr,l[MAXN], r[MAXN];

int main() {
    int n;  cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> l[i] >> r[i];
        cntl += l[i];
        cntr += r[i];
    }

    int beauty = abs(cntl - cntr);
    int idx = 0;

    for(int i = 1; i <= n; i++)
        if(beauty < abs((cntl - (l[i] - r[i])) - (cntr - (r[i] - l[i])))) {
            idx = i;
            beauty = abs((cntl - (l[i] - r[i])) - (cntr - (r[i] - l[i])));
        }
    return cout << idx, 0;
}