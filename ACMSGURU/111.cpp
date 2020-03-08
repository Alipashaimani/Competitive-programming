#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef vector<LL> BigNum;

#define PB push_back

const int D = 1e8, DL = 8;
int maxan;
BigNum x, ans;

int con(){
	BigNum mul;
	mul.reserve(maxan * 2 + 2);
	int p = ans.size() - 1;
	while(ans[p] == 0) p--;
	for(int i = 0; i <= p; i++){
		for(int j = 0; j <= p; j++){
			if(i + j >= mul.size())
				mul.PB(ans[i] * ans[j]);
			else
				mul[i + j] += ans[i] * ans[j];
		}
	}
	for(int i = 0; i < mul.size() - 1; i++)
		mul[i + 1] += mul[i] / D, mul[i] %= D;
	while(mul.back() >= D)
		mul.PB(mul.back() / D), mul[mul.size() - 2] %= D;
	if(mul.size() > x.size())
		return 1;
	if(mul.size() < x.size())
		return -1;
	p = mul.size() - 1;
	while(p >= 0 and mul[p] == x[p]) p--;
	if(p == -1)
		return 0;
	if(mul[p] > x[p])
		return 1;
	return -1;
}

void print(){
	int p = ans.size() - 1;
	while(ans[p] == 0) p--;
	cout << ans[p--];
	while(p >= 0){
		int pr = ans[p];
		int pri = 0;
		while(pr)
			pri++, pr /= 10;
		for(int i = 0; i < DL - pri; i++)
			cout << 0;
		if(ans[p]) cout << ans[p];
		p--;
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	//input
	{
		char c;
		BigNum t;
		while(cin >> c){
			t.PB(c - '0');
			/*if(c == '!'){
				t.pop_back();
				break;
			}*/
		}
		reverse(t.begin(), t.end());
		for(int i = 0; i < t.size(); i += DL){
			int s = 0;
			for(int j = min((int)i + DL - 1, (int)t.size() - 1); j >= i; j--)
				s = s * 10 + t[j];
			x.PB(s);
		}
	}
	maxan = (x.size()) / 2 + 1;
	ans.resize(maxan, 0);
	for(int i = maxan - 1; i >= 0; i--){
		int lo = 0, hi = D;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			ans[i] = mid;
			int b = con();
			if(b == 1)
				hi = mid;
			else if(b == 0){
				print();
				return 0;
			}
			else
				lo = mid;
		}
		ans[i] = lo;
	}
	print();
	return 0;
}
