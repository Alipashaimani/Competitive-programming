#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector <int> adj;
int idx;
bool mark[MAXN];

int main(){
    int n, m;   cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int x, y; cin >> x >> y;
        mark[x] = mark[y] = true;
    }

    for (int i = 1 ; i <= n ; i++)
        if(!mark[i]){
            idx = i;
            break;
        }
        cout << n - 1 << '\n';
    for (int i = 1 ; i <= n ; i++)
        if(i != idx)
            cout << i << " " << idx << '\n';
    return 0;
}