#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int N;
vector <int> v;

void f(int k = 0){
    if(k == v.size() - 1)
        return;
    int t = v[k + 1];
    v[k + 1] = 1;
    f(k + 1);
    cout << t + 1 << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> N;
    if(N % 2 == 0){
        cout << "No solution" << endl;
        return 0;
    }
    while(N > 0){
        v.pb(N & 1);
        N /= 2;
    }
    cout << v.size() - 1 << endl;
    f();
    cout << endl;
	return 0;
}
