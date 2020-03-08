#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e3 + 10;
bool bmark[maxn], dmark[maxn], ans[maxn];
vector <int> v[maxn], ch[maxn];
int h[maxn];

void dfs(int x){
	dmark[x] = true;
	ans[x] = true;
	rep(i, ch[x].size()){
		if(!dmark[ch[x][i]])
			dfs(ch[x][i]);
		if(ans[ch[x][i]]){
			ans[x] = false;
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	queue<int> Q;
	Q.push(1);
	bmark[1] = true;
	while(Q.size()){
		int x = Q.front();
		Q.pop();
		rep(i, v[x].size()){
			if(!bmark[v[x][i]]){
				Q.push(v[x][i]);
				h[v[x][i]] = h[x] + 1;
				bmark[v[x][i]] = true;
			}
			if(h[v[x][i]] == h[x] + 1)
				ch[x].PB(v[x][i]);
		}
	}
	dfs(1);
	if(!ans[1])
		cout << "Vladimir" << endl;
	else
		cout << "Nikolay" << endl;
	return 0;
}
