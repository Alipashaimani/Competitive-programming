#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69;
LL sum[maxn * 4], cnt[maxn * 4];
bool laz[maxn * 4];
vector<LL> all;
int q;

void propagate(int, int, int);

void add(int idx, LL val, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		cnt[id] += val;
		sum[id] += val * all[idx];
		return;
	}
	int mid = (l + r) >> 1;
	propagate(l, r, id);
	add(idx, val, l, mid, id * 2 + 0);
	add(idx, val, mid, r, id * 2 + 1);
	cnt[id] = cnt[id * 2 + 0] + cnt[id * 2 + 1];
	sum[id] = sum[id * 2 + 0] + sum[id * 2 + 1];
	return;
}

LL get(LL k, int l = 0, int r = sz(all), int id = 1){
	if(r - l == 1)
		return k * all[l];
	int mid = (l + r) >> 1;
	propagate(l, r, id);
	if(k <= cnt[id * 2 + 0])
		return get(k, l, mid, id * 2 + 0);
	else
		return sum[id * 2 + 0] + get(k - cnt[id * 2 + 0], mid, r, id * 2 + 1);
}

void clear(LL k, LL val, int l = 0, int r = sz(all), int id = 1){
	if(r - l == 1){
		cnt[id] -= k;
		sum[id] -= val;
		return;
	}
	if(k == cnt[id]){
		laz[id] = true;
		cnt[id] = 0;
		sum[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if(k <= cnt[id * 2 + 0])
		clear(k, val, l, mid, id * 2 + 0);
	else{
		clear(k - cnt[id * 2 + 0], val - sum[id * 2 + 0], mid, r, id * 2 + 1);
		clear(cnt[id * 2 + 0], sum[id * 2 + 0], l, mid, id * 2 + 0);
	}
	cnt[id] = cnt[id * 2 + 0] + cnt[id * 2 + 1];
	sum[id] = sum[id * 2 + 0] + sum[id * 2 + 1];
	return;
}

void propagate(int l, int r, int id){
	if(laz[id]){
		int mid = (l + r) >> 1;
		clear(cnt[id * 2 + 0], sum[id * 2 + 0], l, mid, id * 2 + 0);
		clear(cnt[id * 2 + 1], sum[id * 2 + 1], mid, r, id * 2 + 1);
		laz[id] = false;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stringstream inp;
	{
		string s;
		while(cin >> s){
			q++;
			LL fi, se;
			cin >> fi >> se;
			if(s == "ARRIVE")
				all.PB(se);
			inp << s << ' ' << fi << ' ' << se << '\n';
		}
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < q; i++){
		string s;
		LL fi, se;
		inp >> s >> fi >> se;
		if(s == "ARRIVE"){
			int id = lower_bound(all.begin(), all.end(), se) - all.begin();
			add(id, fi);
		}
		else{
			LL val = get(fi);
			if(cnt[1] >= fi and val <= se){
				cout << "HAPPY\n";
				clear(fi, val);
			}
			else
				cout << "UNHAPPY\n";
		}
	}
	return 0;
}
