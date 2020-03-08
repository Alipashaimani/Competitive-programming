#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;

int par[MAXN], h[MAXN], d[MAXN], mark[MAXN];
vector <pair<int, int>> adj[MAXN];
map<pair<int, int>, int> mp;
vector <pair<int, pair<int, int> > >  es;
string sol[MAXN];

int find(int v) { return par[v] < 0 ? v : par[v] = find(par[v]); }

int dfs(int v, int hi = 0, int baba = -1){
    mark[v] = 1;
    h[v] = d[v] = hi;
    int cnt = 0;
    for(auto i : adj[v])
        if(!mark[i.first]){
            int x = dfs(i.first, hi + 1, v);
            h[v] = min(x, h[v]);
            if(x > d[v])
                sol[i.second] = "any";
        }
        else if(i.first != baba)
            h[v] = min(d[i.first], h[v]);
        else
            cnt++;
    if(cnt > 1)
        h[v] = min(h[v], d[v] - 1);
    return h[v];
}

int main(){
    int n, m;   cin >> n >> m;

    for (int i = 0; i < m; i++){
        int l, r, w;    cin >> l >> r >> w;
        es.push_back({w, {l - 1, r - 1}});
        mp[{l - 1, r - 1}] = mp[{r - 1, l - 1}] = i;
    }

    fill(par, par + n, -1);
    sort(es.begin(), es.end());

    for (int i = 0; i < m; i++){
        int k = i;

        while(k < m && es[i].first == es[k].first)
            k++;

        vector <int> ans;

        for (int j = i; j < k; j++){
            int l = es[j].second.first, r = es[j].second.second;

            if (find(l) == find(r))
                sol[mp[{l, r}]] = "none";

            else {

                int a = find(l), b = find(r);
                if(!mark[a]){
                    vector <pair<int, int>>().swap(adj[a]);
                    ans.push_back(a);
                }

                if(!mark[b]){
                    vector <pair<int, int>>().swap(adj[b]);
                    ans.push_back(b);
                }

                mark[a] = mark[b] = 1;
                adj[b].push_back({a, mp[{l, r}]});
                adj[a].push_back({b, mp[{l, r}]});
            }
        }

        for (auto v : ans)  mark[v] = 0;

        for(auto v : ans)
            if(!mark[v])
                dfs(v);

        for(auto v : ans)   mark[v] = 0;

        for(int j = i; j < k; j++){
            int a = find(es[j].second.first), b = find(es[j].second.second);
            if(a != b)
                par[a] = b;
        }
        i = k - 1;
    }

    for(int i = 0; i < m; i++)
        cout << (sol[i].empty() ? "at least one" : sol[i] ) << '\n';

    return 0;
}
