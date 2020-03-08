#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 100;
int par[MAXN], mark[MAXN];
int t, cnt = 1, n, m, q, x, y;

int lca(int x, int y, int n){
    
    for(int i = 1; i <= n; i++)
        mark[i] = 0;
    
    mark[x] = 1;
    
    while(par[x] != x){
        mark[x] = 1;
        x = par[x];
    }
    
    mark[x] = 1;
    
    while(mark[y]!=1)
        y = par[y];
    
    return y;
}

int main(){
    
    cin >> t;
    while(t--){
        cout << "Case " << cnt++ << ":\n";
        cin >> n;
        for(int i = 1; i <= n; i++)
            par[i] = i;
        
        for(int i = 1; i <= n; i++){
            cin >> m;
            while(m--){
                cin >> x;
                par[x] = i;
            }
        }
        
        cin >> q;
        while(q--){
            cin >> x >> y;
            cout << lca(x, y, n) << '\n';
        }
    }
    return 0;
}
