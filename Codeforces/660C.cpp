#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+9;
int x, y = 0, l, r, m, n, a[MAXN], t, z;

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (x != n && y != n){

        while (y < n && t <= m){
            if (a[y] == 0)
                t++;
            y++;
        }

        if (a[y-1] == 0 && t>m){
            t--;
            y--;
        }

        if (r-l<y-x) {
            l = x;
            r = y;
        }

        if (a[x] == 0)
            t--;

        x++;
    }
    cout << r - l << '\n';

    for (int i = 0; i < n; i++)
        if (l <= i && i < r)
            cout << 1 << ' ';
        else
            cout << a[i] <<' ';

    return 0;
}