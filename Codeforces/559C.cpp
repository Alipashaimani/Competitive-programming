#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x <<" "<< x << endl;
vector<pair<int,int>>vec;
const int MAXN = 1e6;
const int delta = 1e9 + 7;
long long  dp[2010];
long long  f[MAXN];
int power (int a, int b){
    if (b == 0)
        return 1;
    long long c = power(a, b/2);
    c *= c;
    c %= delta;
    if (b & 1)
        c *= a;
    c %= delta;
    return c;
}
void fact(){
    f[0] = f[1] = 1;
    for (int i = 2 ; i < MAXN - 1 ; i++){
        f[i] = f[i-1] * i;
        f[i] %= delta;
    }
}
long long C(int n, int r){
    long long k = f[r] * f[n-r];
    k %= delta;
    return (f[n] * power(k,delta-2))%delta;
}
int main(){
    fact();
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0 ; i < k ; i++){
        int x,y;    cin >> x >> y;
        vec.push_back({x,y});
    }
    vec.push_back({n,m});
    sort(vec.begin(),vec.end());
    for (int i = 0 ; i < (int)vec.size() ; i++){
        int x = vec[i].first, y = vec[i].second;
        dp[i] = C(x + y - 2, x - 1);
        for (int j = i - 1 ; ~j ; j--){
            int _x = vec[j].first, _y = vec[j].second;
            if (_x <= x && _y <= y){
                dp[i] -= dp[j] * C((x-_x) + (y-_y), (x-_x));
                dp[i] %= delta;
                dp[i] += ( dp[i] < 0? delta : 0);
                }
        }
    }
    cout << dp[(int)vec.size()-1] << endl;
}
