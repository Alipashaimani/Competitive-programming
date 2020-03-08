#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 100005;

using namespace std;

vector < pair <int, int> > v[maxn];
int dis[maxn], findd[maxn], go[maxn], daddy[maxn];
vector <int> l;

int main(){
    int n, m;
    int all = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
        all += z;
    }

        queue <int> q;
        fill(dis, dis + n, 1e9);
        dis[0] = 0;
        q.push(0);
        l.push_back(0);
        while (q.size()){
            int u = q.front();
            q.pop();
            for (auto p : v[u]){
                int y = p.first;
                if (dis[u]+1 < dis[y]){
                    q.push(y);
                    dis[y] = dis[u]+1;
                    l.push_back(y);
                }
            }
        }

    {
        fill(findd, findd + n, 1e9);
        fill(go, go+n, -1);
        findd[n-1] = 0;
        reverse(l.begin(), l.end());
        for (int u : l){
            for (auto p : v[u]){
                int y = p.first;
                if (dis[y] == dis[u]+1 && findd[y] + (1-p.second) < findd[u]){
                    findd[u] = findd[y] + (1-p.second);
                    go[u] = y;
                }
            }
        }
    }

    fill(daddy, daddy+n, -1);
    int now = 0;
    while (go[now] != -1){
        daddy[now] = go[now];
        now = go[now];
    }

    cout << all + 2*findd[0] - dis[n-1] << endl;
    for (int i = 0; i < n; i++)
        for (auto p : v[i]){
            int u = p.first;
            if (u < i) continue;
            if (daddy[i] == u || daddy[u] == i){
                if (p.second == 0)
                    cout << i+1 << ' ' << u+1 << ' ' << 1 << endl;
            }
            else if (p.second)
                cout << i+1 << ' ' << u+1 << ' ' << 0 << endl;
        }
    return 0;
}
