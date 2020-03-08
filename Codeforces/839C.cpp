#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 20;

vector<int> adj[MAXN];
int dp[MAXN];
double ans ;

void ex(int v, int par, double p) {
    int cnt = 0;
    dp[v] = dp[par] + 1;

    for(int i = 0; i < adj[v].size(); i++)
        if(adj[v][i] != par)
            cnt++;

    if (cnt == 0)
        ans += p * dp[v];

    else
        for(int i = 0; i < adj[v].size(); i++)
            if(adj[v][i] != par)
                ex(adj[v][i], v, p/cnt);
}

int main() {
    int n; cin >> n;
    while(--n){
        int x, y;    cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ex(1, 0, 1);
    return cout << fixed << setprecision(10) << ans - 1 << '\n', 0;
    return 0;
}