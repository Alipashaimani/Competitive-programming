#include <bits/stdc++.h>

using namespace std;


typedef long long int LL;
typedef pair<LL, LL> pii;
typedef pair<LL, pii> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 10, maxq = 2e5 + 10;
const LL base1 = 313, Mod1 = 1LL * 1000 * 1000 * 1000 + 7;
const LL base2 = 701, Mod2 = 1LL * 1000 * 1000 * 1000 + 9;
pii vec[25][maxq];
vector<piii> all;
string s[maxn];
int psum[maxn];
int n, q;

void build(int id, int l, int r){
	if(r - l == 1){
		vec[id][l] = all[l].R;
		return;
	}
	int mid = (l + r) >> 1;
	build(id + 1, l, mid);
	build(id + 1, mid, r);
	merge(vec[id + 1] + l, vec[id + 1] + mid,
			vec[id + 1] + mid, vec[id + 1] + r,
			vec[id] + l);
	return;
}

int get(pii val, int st, int en, int id = 0, int l = 0, int r = sz(all)){
	if(en <= l or r <= st)
		return 0;
	if(st <= l and r <= en){
		int id1 = lower_bound(vec[id] + l, vec[id] + r, val) - (vec[id] + l);
		int id2 = upper_bound(vec[id] + l, vec[id] + r, val) - (vec[id] + l);
		return id2 - id1;
	}
	int mid = (l + r) >> 1;
	return get(val, st, en, id + 1, l, mid)
		+ get(val, st, en, id + 1, mid, r);
}

void build(void){
	for(int i = 0; i < n; i++){
		LL hsh1 = 0, hsh2 = 0;
		for(int j = sz(s[i]) - 1; j >= 0; j--){
			hsh1 = (hsh1 * base1 + s[i][j]) % Mod1;
			hsh2 = (hsh2 * base2 + s[i][j]) % Mod2;
			all.PB(MP(i, MP(hsh1, hsh2)));
		}
	}
	build(0, 0, sz(all));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	for(int i = 0; i < n; i++)
		psum[i + 1] = psum[i] + sz(s[i]);
	build();
	cin >> q;
	while(q--){
		string pre, suf;
		cin >> pre >> suf;
		int st = lower_bound(s, s + n, pre) - s;
		pre[sz(pre) - 1]++;
		int en = lower_bound(s, s + n, pre) - s;
		LL hsh1 = 0, hsh2 = 0;
		for(int i = sz(suf) - 1; i >= 0; i--){
			hsh1 = (hsh1 * base1 + suf[i]) % Mod1;
			hsh2 = (hsh2 * base2 + suf[i]) % Mod2;
		}
		cout << get(MP(hsh1, hsh2), psum[st], psum[en]) << '\n';
	}
	return 0;
}
