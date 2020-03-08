#include<bits/stdc++.h>
using namespace std;
int a, c[27], ans, zero;
int main(){
	string s;
	cin >> a >> s;
	for (int i = 0 ; i < a ; i++){
		c[(s[i]-'a')]++;
	}
	for ( int i = 0 ; i < 26 ; i++){
		ans += ((c[i] > 1) ? (c[i] - 1) : 0);
		zero += ( c[i] == 0 ? 1 : 0);
	}
	cout << (ans>zero?-1:ans);
}