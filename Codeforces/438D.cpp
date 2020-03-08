#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 100;
pair<long long,long long> segmax[4 * MAXN];
long long segsum[4 * MAXN];
void upd(long long pos, long long val, long long l, long long r, long long id){
    if (l > pos || r <= pos)
        return;
    if (l == r - 1){
        segmax[id] = { val , l };
        segsum[id] = val;
        return;
    }
    long long mid = (l + r) >> 1;
    upd(pos, val, l, mid, id << 1);
    upd(pos, val, mid, r, id << 1 | 1);
    segmax[id] = max(segmax[id << 1], segmax[id << 1 | 1]);
    segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
    return;
}
pair<long long,long long> querymax(long long l, long long r, long long b, long long e, long long id){
    if (r <= b or e <= l)
        return {-1,-1};
    if (l <= b and e <= r)
        return segmax[id];
    long long mid = (b+e) >> 1;
    return max(querymax(l, r, b, mid, id << 1) , querymax(l, r, mid, e, id << 1 | 1));
}
long long querysum(long long l, long long r, long long b, long long e, long long id){
    if (r <= b or e <= l)
        return 0;
    if (l <= b and e <= r)
        return segsum[id];
    long long mid = (b+e) >> 1;
    return querysum(l, r, b, mid, id << 1) + querysum(l, r, mid, e, id << 1 | 1);
}
int main(){
    long long n, q;   cin >> n >> q;
    for (long long i = 0 ; i < n ; i++){
        long long x;  cin >> x;
        upd(i, x, 0, n, 1);
    }
    while(q--){
        long long type;   cin >> type;
        if (type == 1){
            long long l,r;    cin >> l >> r;
            cout << querysum(l-1, r, 0, n, 1) << '\n';
        }else if (type == 2){
            long long l,r,x;  cin >> l >> r >> x;
            while(1){
                pair<long long,long long> qq = querymax(l-1, r, 0, n, 1);
                if (qq.first < x)
                    break;
                upd(qq.second,qq.first % x, 0, n, 1);
            }
        }else{
            long long k,x;    cin >> k >> x;
            upd(k-1, x, 0, n, 1);

        }
    }
}