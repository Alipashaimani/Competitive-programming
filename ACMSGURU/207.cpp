#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

#define int long long

const int maxn = 1000 + 10;
int x[maxn], K[maxn], order[maxn];
int n, m, Y, sum;

bool cmp(int i, int j){
	int val1 = m * x[i] - Y * K[i],
	   val2 = m * x[j] - Y * K[j];
	return val1 > val2;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> Y;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		order[i] = i;
		K[i] = (x[i] * m) / Y;
		sum += K[i];
	}
	sort(order, order + n, cmp);
	m -= sum;
	for(int i = 0; i < m; i++)
		K[order[i]]++;
	for(int i = 0; i < n; i++)
		cout << K[i] << ' ';
	cout << endl;
}
