#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
const int MAX = 10001;

vector< pair< int, pair<int , int > > > adj;
int parent[MAX];

int find(int u);


int main() {
    int t;
    cin >> t;
    
    while(t--) {
        
        int n;
        cin >> n;
        adj.clear();
        
        for (int i = 1; i <= n; i++) {
            int weight, k , v;
            string X;
            
            cin >> X >> k;
            parent[i] = i;
            
            while(k--) {
                cin >> v >> weight;
                
                if(v > i)
                    adj.push_back({weight,{i, v}});
            }
            
        }
        
        sort(adj.begin(), adj.end());
        
        int cost = 0;
        
        for (int i = 0; i < adj.size(); i++){
            int x,y,z;
            x = find(adj[i].S.F);
            y = find(adj[i].S.S);
            z = adj[i].F;
            
            if(x != y){
                cost += z;
                parent[x] = y;
            }
        }
        cout << cost << '\n' ;
    }
    return 0;
}

int find(int u){
    if(u != parent[u])
        parent[u] = find(parent[u]);
    
    return parent[u];
}


