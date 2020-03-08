#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pie;

pie a;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> a.L >> a.R;
	vector<pie> v;
	for(int i = 0; i < n; i++){
		v.PB(MP((a.L * i) % n, (a.R * i) % n));
		v.PB(MP((n - ((a.L * i) % n)) % n, (n - ((a.R * i) % n)) % n));
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i].L << ' ' << v[i].R << endl;
	return 0;
}
