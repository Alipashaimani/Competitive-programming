#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 100;
const int INF = 1e9;
vector<int>adj[MAXN];
int n, k ;
int fr;
int q[MAXN];
int dis[MAXN];
string s[2];
bool fit(int a, int b){return a>= 0 && a < n && s[b][a] == '-' ;}
bool bfs(int v){
    int h = 0, t = 0;
    fill(dis, dis+n+n+20, INF);
    dis[v] = 0;
    q[t++] = v;
    while(t-h){
        v = q[h++];
        for(auto u : adj[v])
            if(dis[u] > dis[v] + 1){
                dis[u] = dis[v] + 1;
                if(u >= n  && dis[u]>u-n)
                    dis[u] = INF ;
                else if(dis[u]>u)
                    dis[u] = INF;
                q[t++] = u;
            }
    }
    if(dis[n-1]!= INF || dis[n+n-1]!= INF || dis[fr]!= INF)
        return true;
    return false;

}
int main(){
    cin >> n >> k;
    cin >> s[0] >> s[1];
    fr = n+n+10;
    for( int i = 0 ; i < n ; i++){
        if(s[0][i] == '-'){
            if(fit(i+1, 0))
                adj[i].push_back(i+1);
            else if(i+1>= n)
                adj[i].push_back(fr);

            if(fit(i-1, 0))
                adj[i].push_back(i-1);

            if(fit(i+k, 1))
                adj[i].push_back(i+n+k);
            else if(i+k >= n)
                adj[i].push_back(fr);

        }
        int j = i + n ;
        if(s[1][i] == '-'){
            if(fit(i+1, 1))
                adj[j].push_back(j+1);
            else if(i+1>= n)
                adj[j].push_back(fr);

            if(fit(i-1, 1))
                adj[j].push_back(j-1);
            if(fit(i+k, 0))
                adj[j].push_back(i+k);
            else if(i+k>=n)
                adj[j].push_back(fr);
        }
    }

    cout <<(bfs(0)==1?"YES":"NO") << '\n';

}

