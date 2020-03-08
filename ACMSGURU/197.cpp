#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define sz(x) ((int)(x).size())

vector<int> wannapow;
int m, Mod;

struct matrix{
	int a[35][35];
	int n, m;
	matrix(int x, int y, int val = 0){
		n = x;
		m = y;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = (i == j) * val;
		return;
	}
	int *operator[](int i){
		return a[i];
	}
};

matrix operator*(matrix &A, matrix &B){
	matrix ret(A.n, B.m);
	for(int i = 0; i < A.n; i++)
		for(int k = 0; k < A.m; k++)
			for(int j = 0; j < B.m; j++)
				ret[i][j] = (ret[i][j] + ((A[i][k] * B[k][j]) % Mod)) % Mod;
	return ret;
}

matrix Pow(matrix A){
	matrix ret(A.n, A.m, 1), an = A;
	int pos = 0;
	for(int i = 0; pos < sz(wannapow); i++, an = an * an)
		if(i == wannapow[pos])
			ret = ret * an, pos++;
	return ret;
}

inline void unmerge(vector<int> &v){
	int rem = 0;
	for(int i = sz(v) - 1; i >= 0; i--){
		int tmp = v[i] & 1;
		v[i] = (rem * 10 + v[i]) >> 1;
		rem = tmp;
	}
	while(v.size() and v.back() == 0)
		v.pop_back();
	return;
}

void input(void){
	string s;
	cin >> s;
	vector<int> v;
	for(int i = sz(s) - 1; i >= 0; i--)
		v.PB(s[i] - '0');
	for(int i = 0; i < sz(v); i++){
		v[i]--;
		if(v[i] == -1)
			v[i] = 9;
		else
			break;
	}
	while(v.size() and v.back() == 0)
		v.pop_back();
	int p = 0;
	while(v.size()){
		if(v[0] & 1)
			wannapow.PB(p);
		p++;
		unmerge(v);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	cin >> m >> Mod;
	matrix fact(1 << m, 1 << m);
	for(int mask1 = 0; mask1 < (1 << m); mask1++){
		for(int mask2 = 0; mask2 < (1 << m); mask2++){
			bool ok = true;
			for(int i = 0; i + 1 < m; i++)
				if(((mask1 >> i) & 1) == ((mask1 >> (i + 1)) & 1)
						and ((mask2 >> i) & 1) == ((mask2 >> (i + 1)) & 1)
						and ((mask1 >> i) & 1) == ((mask2 >> i) & 1))
					ok = false;
			fact[mask1][mask2] = ok;
		}
	}
	matrix factn = Pow(fact);
	matrix base(1 << m, 1);
	for(int i = 0; i < (1 << m); i++)
		base[i][0] = 1;
	matrix mans = factn * base;
	int ans = 0;
	for(int i = 0; i < (1 << m); i++)
		ans = (ans + mans[i][0]) % Mod;
	cout << ans << endl;
	return 0;
}
