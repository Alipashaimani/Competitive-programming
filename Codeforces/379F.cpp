#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
const int MAXLOG = 25;
int dp[MAXN][MAXLOG + 2];
int h[MAXN];
int p1 = 1, p2 = 3;
int ans = 2;

int lca (int u, int v) {
    if (h[u] > h[v])
        swap(v, u);
    for (int i = MAXLOG - 1; i >= 0; --i)
        if (h[dp[v][i]] >= h[u])
            v = dp[v][i];

    if (v == u)
        return v;

    for (int i = MAXLOG - 1; ~i; --i)
        if (dp[v][i] != dp[u][i])
            u = dp[u][i], v = dp[v][i];

    return dp[u][0];
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;  cin >> n;
    int cnt = 4;
    h[1] = h[2] = h[3] = 1;

    while(n--) {
        int x;  cin >> x;   x--;
        h[cnt] = h[cnt + 1] =  h[x] + 1;
        dp[cnt][0] = dp[cnt + 1][0] = x;

        for (int i = 1 ; i < 25 ; i++) {
            dp[cnt][i] = dp[dp[cnt][i-1]][i-1];
            dp[cnt+1][i] = dp[dp[cnt+1][i-1]][i-1];
        }

        int v1 = lca(cnt, p1);
        int v2 = lca(cnt, p2);

        int dist1 = h[p1] - h[v1] + h[cnt] - h[v1];
        int dist2 = h[p2] - h[v2] + h[cnt] - h[v2];

        if (dist1 > dist2) {
            if (dist1 > ans) {
                p2 = cnt;
                ans = dist1;
            }
        } else if (dist2 > ans) {
            p1 = cnt;
            ans = dist2;
        }

        cout << ans << endl;
        cnt += 2;
    }
    return 0;
}