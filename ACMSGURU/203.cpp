#include <bits/stdc++.h>

using namespace std;

#define MP make_pair

typedef long long int ll;

const int maxn = 5e5 + 10;
int a[maxn], f[maxn*2], par[maxn*2], n;

void F(int x){
	if(x == 2 * n - 2){
		f[x] = 0;
		return;
	}
	if(f[par[x]] == 0)
		F(par[x]);
	f[x] = f[par[x]] + 1;
}

int main(){
	//ios_base::sync_with_stdio(false);
	cin >> n;
	queue<pair<ll, int> > Q1, Q2;
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		Q1.push(MP(a[i], i));
	}
	if(n == 1){
		cout << Q1.front().first << endl;
		return 0;
	}
	int p = n;
	while(Q1.size() + Q2.size() > 1){
		pair<ll, int> X, Y;
		if(Q2.size() == 0){
			X = Q1.front();
			Q1.pop();
			Y = Q1.front();
			Q1.pop();
		}
		else if(Q1.size() == 0){
			X = Q2.front();
			Q2.pop();
			Y = Q2.front();
			Q2.pop();
		}
		else{
			if(Q1.front() < Q2.front()){
				X = Q1.front();
				Q1.pop();
				if(Q1.size() and Q1.front() < Q2.front()){
					Y = Q1.front();
					Q1.pop();
				}
				else{
					Y = Q2.front();
					Q2.pop();
				}
			}
			else{
				X = Q2.front();
				Q2.pop();
				if(Q2.size() and Q2.front() < Q1.front()){
					Y = Q2.front();
					Q2.pop();
				}
				else{
					Y = Q1.front();
					Q1.pop();
				}
			}
		}
		Q2.push(MP(X.first + Y.first, p));
		par[X.second] = p;
		par[Y.second] = p;
		p++;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		F(i);
		ans += (ll)a[i] * f[i];
	}
	cout << ans << endl;
	return 0;
}
