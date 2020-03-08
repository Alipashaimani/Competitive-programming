#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[3] = {0, 1, 2};
	int s[3][3];
	int Min = 100000, Minid;
	for(int i = 0; i < 6; next_permutation(a, a + 3), i++){
		for(int ii = 0; ii < 3; ii++)
			for(int jj = 0; jj < 3; jj++)
				s[ii][jj] = (a[ii] == jj);
		int cnt = 0;
		for(int ii = 0; ii < n; ii++)
			for(int jj = 0; jj < m; jj++)
				cnt += s[ii % 3][jj % 3];
		if(cnt < Min){
			Min = cnt;
			Minid = i;
		}
	}
	for(int i = 0; i <= Minid; next_permutation(a, a + 3), i++){
		for(int ii = 0; ii < 3; ii++)
			for(int jj = 0; jj < 3; jj++)
				s[ii][jj] = (a[ii] == jj);
		if(i == Minid){
			for(int ii = 0; ii < n; ii++){
				for(int jj = 0; jj < m; jj++)
					cout << (s[ii % 3][jj % 3] ? '#' : '0');
				cout << '\n';
			}
		}
	}
	return 0;
}
