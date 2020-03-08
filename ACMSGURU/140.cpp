#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define endl '\n'

const int maxn = 110, maxp = 10010;
int a[maxn], x[maxn], mod[maxp], par[maxp];
int n, p, b;
bool mark[maxp];
vector<int> edge;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(mod, -1, sizeof mod);
	cin >> n >> p >> b;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mod[a[i] % p] = i;
		edge.PB(a[i] % p);
	}
	sort(edge.begin(), edge.end());
	edge.resize(unique(edge.begin(), edge.end()) - edge.begin());
	queue<int> Q;
	Q.push(0);
	mark[0] = true;
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < edge.size(); i++){
			int e = edge[i];
			if(!mark[(v + e) % p]){
				mark[(v + e) % p] = true;
				par[(v + e) % p] = e;
				Q.push((v + e) % p);
			}
		}
	}
	if(!mark[b]){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int v = b;
	while(v){
		x[mod[par[v]]]++;
		v = (((v - par[v]) % p) + p) % p;
	}
	for(int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << endl;
	return 0;
}
