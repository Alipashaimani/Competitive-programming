#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
long long seg[4 * MAXN];
long long lz[4 *MAXN];

void shift(int id, int b, int e) {
    lz[id << 1] += lz[id];
    lz[id << 1 | 1] += lz[id];
    int mid = (b+e) >> 1;
    seg[id << 1] += lz[id] * (mid - b);
    seg[id << 1 | 1] += lz[id] * (e - mid);
    lz[id] = 0;
}

void update (int l, int r, int x, int b, int e, int id) {
    if ((r <= b) || (l >= e))
        return;
    
    if (l <= b && r >= e) {
        lz[id] += x;
        seg[id] += 1LL * x * (e - b);
        return;
    }
    
    shift(id, b, e);
    
    int mid = (b+e) >> 1;
    update(l, r, x, b, mid, id << 1);
    update(l, r, x, mid, e, id << 1 | 1);
    
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}


long long query (int l, int r, int b, int e, int id) {
    if ((r <= b) || (l >= e))
        return 0;
    if (l <= b && r >= e)
        return seg[id];
    
    shift(id, b, e);
    
    int mid = (b+e) >> 1;
    return query(l, r, b, mid, id << 1) +
    query(l, r,  mid, e, id << 1 | 1);
    
}



int main() {
    int t;  cin >> t;
    while(t--){
        memset(seg, 0, sizeof(seg));
        memset(lz, 0, sizeof(lz));
        
        int n, c;   cin >> n >> c;
        while(c--){
            int x;  cin >> x;
            if (x){
                int a,b;    cin >> a >> b;
                a--;
                cout << query(a, b, 0, n, 1) << endl;;
            }else{
                int a,b,c2;  cin >> a >> b >> c2;
                a--;
                update(a, b, c2, 0, n, 1);
            }
        }
    }
    return 0;
}

