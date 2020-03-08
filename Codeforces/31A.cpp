#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
int n, table[MAXN];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> table[i];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n ; ++j)
                if (i != j && j != k && k != i && table[j] == table[i] + table[k])
                    return cout << j+1 << " " << i+1 << " " << k+1  , 0;

    return cout << -1 , 0;
}
