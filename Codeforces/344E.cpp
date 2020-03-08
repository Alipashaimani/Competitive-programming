#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m;
long long p[MAXN], red[MAXN];
bool check(long long mid){
    long long mamba, idx = 0;
    for (int i = 0 ; i < n; i++){
        mamba = 0;
        if (red[idx] <= p[i]){
            mamba += (p[i] - red[idx]);
            if (mamba <= mid){
                long long jamba = max((mid-mamba)/2 , mid - 2 * mamba);
                idx = upper_bound(red, red + m , p[i] + jamba) - red;
            }
            else{
                return 0;
            }
        }
        else {
            idx = upper_bound(red, red+m, p[i] + mid) - red;
        }
//        cout << i <<  " " << idx << endl;
        if (idx >= m)
            return 1;
    }
    return 0;
}
int main(){
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        cin >> p[i];
    }
    for (int i = 0 ; i < m ; i++){
        cin >> red[i];
    }
    long long b = -1 , e = 1e18 + 10;
        while((e - b) != 1){
            long long mid = (b + e) >> 1;
            if (check(mid)){
                e = mid;
            }else{
                b = mid;
            }
        }
    cout << e << endl;
}
