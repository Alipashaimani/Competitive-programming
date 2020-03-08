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

const int maxn = 10;
vector <int> v[maxn][maxn];
int m, d[maxn];
pair <int, bool> p[300];
int End = 1;

void shuf(int s, int e, int c){
	for(int i = e + c; i >= s + c; i --)
		p[i] = p[i - c];
}

void F(int x, int it){
	while(d[x]){
		rep(i, 7){
			if(v[x][i].size()){
				shuf(it, End, 1);
				End ++;
				p[it] = mp(v[x][i].back(), 0);
				v[x][i].pop_back();
				d[x] --;
				d[i] --;
				m --;
				F(i, it + 1);
				break;
			}
			else if(v[i][x].size()){
				shuf(it, End, 1);
				End ++;
				p[it] = mp(v[i][x].back(), 1);
				v[i][x].pop_back();
				d[i] --;
				d[x] --;
				m --;
				F(i, it + 1);
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> m;
	int mm = m;
	reu(i, 1, m){
		int fi, se;
		cin >> fi >> se;
		v[fi][se].pb(i);
		d[fi] ++;
		d[se] ++;
	}
	vector<int> t;
	rep(i, 7)
		if(d[i] & 1)
			t.pb(i);
	if(t.size() > 2){
		cout << "No solution" << endl;
		return 0;
	}
	F(t.back(), 1);
	if(m != 0){
		cout << "No solution" << endl;
		return 0;
	}
	rer(i, 1, End)
		cout << p[i].p1 << ' ' << (p[i].p2 ? "-" : "+") << endl;
	return 0;
}
