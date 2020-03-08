#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;

int32_t main(){
	cin >> s;
	n=s.size();
	bool fl=true;
	for (int i = 1; i < n; i++)
		if (s[i] != s[0] && (n%2==0 || i != n/2))
			fl=false;
	if (fl){
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 1; i < n; i++){
		string t=s.substr(i, n-i)+s.substr(0,i);
		string t2=t;
		reverse(t2.begin(),t2.end());
		if (t==t2&&t!=s){
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
}
