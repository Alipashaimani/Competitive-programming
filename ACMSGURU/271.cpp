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

int main(){
	ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    deque <string> S;
    deque <string> D;
    int x = 1;
    rep(i, n){
        string s;
        cin >> s;
        D.push_back(s);
        if(D.size() > k){
            S.push_back(D.back());
            D.pop_back();
        }
    }
    rep(i, m){
        string s;
        cin >> s;
        if(s[0] == 'R'){
            if(x == 1)
                x = 2;
            else
                x = 1;
        }
        else{
            s.erase(s.begin(), s.begin() + 4);
            s.erase(s.end() - 1);
            if(x == 1){
                D.push_front(s);
                if(D.size() > k){
                    S.push_front(D.back());
                    D.pop_back();
                }
            }
            else{
                D.push_back(s);
                if(D.size() > k){
                    S.push_front(D.front());
                    D.pop_front();
                }
            }
        }
    }
    if(x == 2){
        while(D.size()){
            cout << D.back() << endl;
            D.pop_back();
        }
    }
    else{
        while(D.size()){
            cout << D.front() << endl;
            D.pop_front();
        }
    }
    while(S.size()){
        cout << S.front() << endl;
        S.pop_front();
    }
	return 0;
}
