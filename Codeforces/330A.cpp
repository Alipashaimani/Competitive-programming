#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
string table[MAXN];
string table2[MAXN];
int ans = 0;
int main(){
    int n,m;    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        cin >> table[i];
    }

    for (int i = 0 ; i < n ; i++){
        if (table[i].find('S') > m)
            for (int j = 0 ; j < m ; j++){
                if (table[i][j] == '.')
                    ans++,table[i][j] = ',';
            }
    }
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            table2[i] += table[j][i];
        }
    }

    for (int i = 0 ; i < m ; i++){
        if (table2[i].find('S') > n)
            for (int j = 0 ; j < n ; j++){
                if (table2[i][j] == '.')
                    ans++,table2[i][j] = ',';
            }
    }
    cout << ans << endl;
}