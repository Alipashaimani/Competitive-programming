#include <bits/stdc++.h>

using namespace std;


const int MAXN = 1000 + 10;
int n, m, ans;
int arr[MAXN][MAXN];
vector <int> row[MAXN], col[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1){
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (arr[i][j] == 0) {
                int a = lower_bound(row[i].begin(), row[i].end(), j) - row[i].begin();
                int b = lower_bound(col[j].begin(), col[j].end(), i) - col[j].begin();

                if (a < row[i].size())
                    ans++;

                if (b < col[j].size())
                    ans++;

                if (a > 0)
                    ans++;

                if (b > 0)
                    ans++;


            }

    cout << ans;
    return 0;
}