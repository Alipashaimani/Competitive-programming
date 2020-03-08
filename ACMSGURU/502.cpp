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

vector <int> num, num2;
string s;

void input(){
    cin >> s;
    rep(i, s.size()){
        num.pb(s[i] - 48);
        num2.pb(s[i] - 48);
    }
}

bool check(){
    int Mod = 0;
    if(num[0] == 0)
        return false;
    rep(i, num.size()){
        Mod *= 10;
        Mod += num[i];
        Mod %= 17;
    }
    if(Mod == 0)
        return true;
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    input();
    do{
        if(check()){
            rep(i, num.size())
                cout << num[i];
            cout << endl;
            return 0;
        }
        next_permutation(num.begin(), num.end());
    }while(num != num2);
    cout << -1 << endl;
	return 0;
}
