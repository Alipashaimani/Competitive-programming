#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

vector <int> a;
string s;

void input(){
    cin >> s;
    rep(i, s.size())
        if(s[i] == '(')
            a.pb(0);
        else
            a.pb(1);
}

int main(){
	ios_base::sync_with_stdio(false);
    input();
    int x[2] = {0, 0};
    int n = a.size();
    for(int i = n - 1; i > 0; i--){
        x[a[i]]++;
        if(a[i] == 1 && a[i - 1] == 0 && x[0] < x[1] - 1){
            x[1] --;
            rep(j, i - 1)
                cout << s[j];
            cout << ")(";
            rep(j, x[0])
                cout << '(';
            rep(j, x[1])
                cout << ')';
            cout << endl;
            return 0;
        }
    }
    cout << "No solution" << endl;
	return 0;
}
