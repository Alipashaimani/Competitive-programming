#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 300010;
const ll mod = 1e9 + 7;

int t, n, k;
char s[MAXN];
ll h[MAXN], base[MAXN];
map<ll , int > vis;
int main(){
    base[0] = 1;
    for(int i = 1 ; i < MAXN; i++){base[i] = base[i-1] * mod;}
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%s",&n,&k,s+1);
        for ( int i = 1 ; i <= n ; i++) h[i] = h[i-1] * mod + s[i];
        vis.clear();
        for ( int i = k ; i <= n ; i++) vis[h[i]-h[i-k]*base[k]] = 1;
        printf("%d\n", (int)vis.size());
    }
    return 0;
}

