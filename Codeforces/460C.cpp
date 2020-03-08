#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 1000;
ll flower[MAXN];
ll hight[MAXN];
int n, m, w;

bool check(ll x){
    ll need = 0, now = 0;

    for (int i = 0; i < n; i++){
        now += hight[i];
        hight[i] = 0;
        if ((flower[i] + now) < x){

            need += x - (flower[i] + now);
            hight[i + w] -= x - (flower[i] + now);
            now += x - (flower[i] + now);
        }
    }
    return need <= m;

}
int main(){
    cin >> n >> m >> w;

    for (int i = 0 ; i < n ; i++)
        cin >> flower[i];

    ll l = 0, r = 2e9 + 1e5;

    while(r - l  > 1){
        ll mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    return cout << l << '\n', 0;
}