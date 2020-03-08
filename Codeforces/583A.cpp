#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3;
bool mark[2][MAXN];
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n*n; i++) {
        int x, y;
        cin >> x >> y;
        if(mark[0][x] or mark[1][y])
            continue;
        else {
            cout << i << ' ';
            mark[0][x] = mark[1][y] = 1;
        }
    }
}