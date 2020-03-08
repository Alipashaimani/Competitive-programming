#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

int n, m, enemy[N][N], tower[N][N], cnte, cntt, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string mat[N];
vector<int> adj[N];
vector<pair<int,int> > shoter[N];
stack<int>scc;
bool mark[N];

bool dfs (int x) {
    if (mark[x^1])
        return false;
    
    if (mark[x])
        return true;
    
    mark[x] = true;
    scc.push(x);
    
    for (int v = 0 ; v <  adj[x].size() ; v++)
        if(!dfs(adj[x][v]))
            return false;
    
    return true;
}

bool find (int i, int j, int d, int t1, int t2) {
    
    if (i < 0 || i == n || j < 0 || j == m || mat[i][j] == '#')
        return true;
    
    if (mat[i][j] == 'T')
        return false;
    
    bool ans = find(i + dx[d], j + dy[d], d, t1, t2);
    
    if (ans && mat[i][j] == 'n')
        shoter[enemy[i][j]].push_back(make_pair(t1, t2));
    
    return ans;
}

void add1 (int i, int v) {adj[((i << 1) + v)^1].push_back((i << 1) + v);}

void add2 (int i, int v1, int j, int v2) {adj[((i << 1) + v1)^1].push_back((j << 1) + v2),adj[((j << 1) + v2)^1].push_back((i << 1) + v1);}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    
    cnte = cntt = 0;
    memset(enemy, 0, sizeof(enemy));
    memset(tower, 0, sizeof(tower));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'n')
                enemy[i][j] = cnte++;
            if (mat[i][j] == 'T')
                tower[i][j] = cntt++;
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'T')
                for (int k = 0; k < 4; k++) {
                    int t = (tower[i][j] + (k % 2) * cntt);
                    if (!find(i+dx[k], j + dy[k], k, t, (int)(k<2)))
                        add1(t, (int)(k<2)^1);
                }
    
    
    for (int i = 0; i < cnte; i++) {
        if (shoter[i].size() == 1)
            add1(shoter[i][0].first, shoter[i][0].second);
        
        else if (shoter[i].size() == 2)
            add2(shoter[i][0].first, shoter[i][0].second, shoter[i][1].first, shoter[i][1].second);
    }
    
    memset(mark, 0, sizeof(mark));
    
    for(int i = 0; i< (cntt << 2); i += 2) {
        if(!mark[i] && !mark[i+1]){
            while(scc.size())
                scc.pop();
            if(!dfs(i)) {
                while (scc.size()) {
                    mark[scc.top()] = false;
                    scc.pop();
                }
                if(!dfs(i+1))
                    break;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'T') {
                if (!mark[tower[i][j]*2+1] &&  mark[(tower[i][j]+cntt)*2+1])
                    cout << 1 ;
                if (mark[tower[i][j]*2+1]  &&  mark[(tower[i][j]+cntt)*2+1])
                    cout << 2 ;
                if (mark[tower[i][j]*2+1]  && !mark[(tower[i][j]+cntt)*2+1])
                    cout << 3 ;
                if (!mark[tower[i][j]*2+1] && !mark[(tower[i][j]+cntt)*2+1])
                    cout << 4 ;
                
            }
            else
                cout << mat[i][j];
        cout << '\n';
    }
    return 0;
}


