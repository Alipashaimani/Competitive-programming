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
	string s;
	getline(cin, s);
	int ans = 0;
	bool x = false;
	rep(i, s.size()){
		if(x){
			if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' ')
				continue;
			else if(s[i] == ')')
				x = false;
			else{
				ans ++;
				if(s[i] != '(')
					x = false;
			}
		}
		else{
			if(s[i] == '(')
				x = true;
			else if(s[i] == ')')
				ans ++;
		}
	}
	if(x)
		ans ++;
	cout << ans << endl;
	return 0;
}
