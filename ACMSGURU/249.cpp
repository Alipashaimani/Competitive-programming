#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)t; (i)++)
#define reu(i, s, e) for(ll (i) = (ll)s; (i) <= (ll)e; (i)++)
#define rer(i, s, e) for(ll (i) = (ll)s; (i) < (ll)e; (i)++)
#define mset(arr, val) memset(arr, val, sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int n, m;
ll ans;    // = (000...0)2

void fp(int, int);

void f(int i, int e){
    if(i == n && e == n){
        printf("%d ", ans);
        return;
    }
    if(i == m + n && e == m + n){
        f(0, n);
        printf("\n");
        return;
    }
    f(i + 1, e);
    ans += 1 << i;
    fp(i + 1, e);
    ans -= 1 << i;
}

void fp(int i, int e){
    if(i == n && e == n){
        printf("%d ", ans);
        return;
    }
    if(i == m + n && e == m + n){
        f(0, n);
        printf("\n");
        return;
    }
    ans += 1 << i;
    f(i + 1, e);
    ans -= 1 << i;
    fp(i + 1, e);
}

int main(){
	ios_base::sync_with_stdio(false);
    scanf("%d%d", &m, &n);
    f(n, m + n);
	return 0;
}
