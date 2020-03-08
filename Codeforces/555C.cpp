#include <bits/stdc++.h>
using namespace std;

map<int, int> X, Y;
int n, q;
set<int>s;

int main() {
    cin >> n >> q;

    X[0] = Y[0] = 0;

    for (int i = 0; i < q; i++) {
        int x, y; char d;
        cin >> x >> y >> d;

        if (s.find(x) != s.end())
            cout <<"0\n";

        else{
            s.insert(x);
            auto a = X.lower_bound(x); a--;
            auto b = Y.lower_bound(y); b--;
            X[x] = a->second;
            Y[y] = b->second;

            if (d == 'U') {
                Y[b->first] = x;
                cout << y - X[x] << '\n';
            }
            else {
                X[a->first] = y;
                cout << x - Y[y] << '\n';
            }
        }
    }
    return 0;
}