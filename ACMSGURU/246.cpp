#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n;
    k = n / 2 + 2;
    ll t = n * k / __gcd(n, k);
    cout << __gcd(n, k) * (t / k / 2) + 1;
	return 0;
}
