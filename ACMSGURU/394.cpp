#include <bits/stdc++.h>

using namespace std;


typedef long long int LL;
typedef pair<LL, LL> pii;
typedef pair<LL, pii> piii;
typedef pair<pii, LL> Piii;

#define sz(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = (1000 * 100 + 85 - 69) << 1;
vector<piii> recadd, recrem;
int fen[maxn];
Piii point[maxn];
int n, k;
LL w[maxn], ans[maxn];
vector<int> vecans, yall;

void add(int val, int idx){
	idx++;
	while(idx < maxn){
		fen[idx] += val;
		idx += idx & -idx;
	}
	return;
}

void add(int val, int st, int en){
	add(val, st);
	add(-val, en);
	return;
}

int get(int idx){
	int ret = 0;
	idx++;
	while(idx > 0){
		ret += fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void solve(void){
	for(int i = 0; i < recadd.size(); i++){
		yall.PB(recadd[i].R.L);
		yall.PB(recadd[i].R.R + 1);
	}
	sort(yall.begin(), yall.end());
	yall.resize(unique(yall.begin(), yall.end()) - yall.begin());
	int p = 0, q = 0;
	for(int i = 0; i < n; i++){
		while(p < sz(recadd) and recadd[p].L <= point[i].L.L){
			int id1 = lower_bound(yall.begin(), yall.end(), recadd[p].R.L) - yall.begin(),
				id2 = upper_bound(yall.begin(), yall.end(), recadd[p].R.R) - yall.begin();
			add(+1, id1, id2);
			p++;
		}
		while(q < sz(recrem) and recrem[q].L <= point[i].L.L){
			int id1 = lower_bound(yall.begin(), yall.end(), recrem[q].R.L) - yall.begin(),
				id2 = upper_bound(yall.begin(), yall.end(), recrem[q].R.R) - yall.begin();
			add(-1, id1, id2);
			q++;
		}
		int id = upper_bound(yall.begin(), yall.end(), point[i].L.R) - yall.begin() - 1;
		ans[point[i].R] = get(id);
	}
	return;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%lld%lld%lld", &point[i].L.L, &point[i].L.R, w + i);
		point[i].R = i;
		LL x1 = point[i].L.L, y1 = point[i].L.R;
		point[i].L.L = x1 - y1;
		point[i].L.R = x1 + y1;
		recadd.PB(MP(x1 - w[i] - y1, MP(x1 - w[i] + y1, x1 + y1 + w[i])));
		recrem.PB(MP(x1 + w[i] - y1 + 1, MP(x1 - w[i] + y1, x1 + y1 + w[i])));
	}
	sort(recadd.begin(), recadd.end());
	sort(recrem.begin(), recrem.end());
	sort(point, point + n);
	solve();
	for(int i = 0; i < n; i++)
		if(ans[i] > k)
			vecans.PB(i + 1);
	cout << sz(vecans) << '\n';
	for(int i = 0; i < sz(vecans); i++)
		cout << vecans[i] << ' ';
	cout << '\n';
	return 0;
}
