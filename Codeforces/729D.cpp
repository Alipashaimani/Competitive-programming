#include<bits/stdc++.h>
using namespace std;
int a,b;
int ships;
vector<int>shots;
int n;
int main(){
	string s;
	cin >> n >> a >> b >> n >> s;
	n = s.size();

	for (int l = 0; l < n; ){
		if (s[l] == '1'){
			l++;
			continue;
		}

		int r = l;

		while (r < n && s[r] == '0')
			r++;

		if (r - l >= b){
			ships += (r-l)/b;
			int p = l;
			int o = r - l;
			while(o >= b){
				shots.push_back(p+b);
				p+= b ;
				o-= b ;
			}
		}
		l = r;
	}

	int x = ships - a + 1;

	cout << x << '\n';

	for ( int i = 0 ; i < x ; i++)
		cout << shots[i] << " ";

	cout << '\n';
	return 0;
}
