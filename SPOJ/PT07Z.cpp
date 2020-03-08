#include<bits/stdc++.h>
using namespace std;

vector <int> c1[10000 + 10];
int mark [10000 + 10], d = 0, k = 1;

void dfs1(int a, int c, int KK) {
    mark[a] = KK;
    for (int i = 0; i < c1[a].size(); ++i) {
        if (mark [c1[a][i]] != KK) {
            dfs1(c1[a][i], c + 1, KK);
        }
        if (d <= c) {
            k = a;
            d = max(d, c);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        c1[a].push_back(b);
        c1[b].push_back(a);
    }
    dfs1(1, 0, 1);
    dfs1(k, 0 , 2);
    cout << d << '\n';
    return 0;
}
