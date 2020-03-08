#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 100000;
int seg[4 * MAXN];
bool lazy[4 * MAXN];
void shift(int b, int e, int id){
    if (lazy[id]) {
        
        lazy[id << 1] ^= lazy[id];
        lazy[id << 1 | 1] ^= lazy[id];
        
        int mid = (b + e) >> 1;
        
        seg[id << 1] = (mid - b) - seg[id << 1];
        seg[id << 1 | 1] = (e - mid) - seg[id << 1 | 1];
        lazy[id] = 0;
    }
}

int query(int l, int r, int b, int e, int id){
    if (r <= b or e <= l)
        return 0;
    
    if (l <= b and e <= r)
        return seg[id];
    
    shift(b, e, id);
    
    int mid = (b + e) >> 1;
    return query(l, r, b, mid, id << 1) + query(l, r, mid, e, id << 1 | 1);
}
void upd(int l, int r, int b, int e, int id){
    if (r <= b or e <= l)
        return;
    if (l <= b and e <= r){
        lazy[id] ^= 1;
        seg[id] = (e-b) - seg[id];
        return;
    }
    
    shift(b, e, id);
    
    int mid = (b+e) >> 1;
    
    upd(l, r, b, mid, id << 1);
    upd(l, r, mid, e, id << 1 | 1);
    
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int32_t main(){
    int n,m;    cin >> n >> m;
    while(m--){
        int a,b,c;  cin >> a >> b >> c; b--;
        if ( a == 0){
            upd(b, c, 0, n, 1);
        }else{
            cout << query(b, c, 0, n, 1) << '\n' << flush;
        }
    }
}

