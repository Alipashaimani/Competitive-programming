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
    string s;
    cin >> s;
    stack <char> S, T;
    rep(i, s.size()){
        if(s[i] == 'L'){
            if(S.size()){
                T.push(S.top());
                S.pop();
            }
        }
        else if(s[i] == 'R'){
            if(T.size()){
                S.push(T.top());
                T.pop();
            }
        }
        else
            S.push(s[i]);
    }
    while(S.size()){
        T.push(S.top());
        S.pop();
    }
    while(T.size()){
        printf("%c", T.top());
        T.pop();
    }
    printf("\n");
	return 0;
}
