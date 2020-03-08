#include<bits/stdc++.h>
using namespace std;

int n;
map<int,pair<int, int> >row, col;

int main(){
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            char c; cin >> c;
            if (c == '.'){
                row[i] = {i, j};
                col[j] = {i, j};
            }
        }


    if (row.size() == n)
        for (auto r: row)
            cout << r.second.first << " " << r.second.second << '\n';

    else if(col.size() == n)
        for (auto c: col)
            cout << c.second.first << " " << c.second.second << '\n';

    else
        cout << -1;
    return 0;
}