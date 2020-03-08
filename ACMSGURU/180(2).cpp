#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 10;
int t[maxn * 4], n;
vector<int> a, v;
long long int ans;

void update(int idx, int L = 0, int R = a.size(), int id = 1){
	t[id]++;
	if(R - L == 1)
		return;
	int mid = (L + R) >> 1;
	if(idx < mid)
		update(idx, L, mid, id * 2 + 0);
	else
		update(idx, mid, R, id * 2 + 1);
}

long long int get(int l, int r, int L = 0, int R = a.size(), int id = 1){
	if(L == l and R == r)
		return t[id];
	int mid = (L + R) >> 1;
	long long int ret = 0;
	if(r > mid)
		ret += get(max(l, mid), r, mid, R, id * 2 + 1);
	if(l < mid)
		ret += get(l, min(mid, r), L, mid, id * 2);
	return ret;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.PB(x);
		a.PB(x);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	for(int i = 0; i < n; i++){
		int lo = lower_bound(a.begin(), a.end(), v[i]) - a.begin();
		int up = upper_bound(a.begin(), a.end(), v[i]) - a.begin();
		if(up != a.size())
			ans += get(up, a.size());
		update(lo);
	}
	cout << ans << endl;
	return 0;
}
