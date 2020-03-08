#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

const int maxn = 1000;
string vec[maxn];

void solve(void){
	string s;
	getline(cin, s);
	s = s.substr(1, sz(s) - 2);
	int last = -1;
	bool newword = true;
	char lastchar = 'a';
	for(int i = 0; i < sz(s); i++){
		if(s[i] == ' ')
			newword = true;
		else if(s[i] == '-'){
			if(lastchar != '-'){
				last++;
				vec[last] = "";
			}
			vec[last] += "-";
			lastchar = '-';
			newword = true;
		}
		else{
			if(newword){
				last++;
				vec[last] = "";
			}
			vec[last] += s[i];
			lastchar = s[i];
			newword = false;
		}
	}
	last++;
	string ret;
	for(int i = 0; i < last; i++){
		if(vec[i][0] == '-'){
			if(sz(vec[i]) == 1){
				if(i == 0 or i == last - 1){
					cout << "error" << endl;
					return;
				}
				else{
					ret = ret.substr(0, sz(ret) - 1);
					ret += "-";
				}
			}
			else{
				int cnt = sz(vec[i]);
				if(i == 0)
					ret += " ";
				while(cnt % 3)
					ret += "-- ", cnt -= 2;
				while(cnt)
					ret += "--- ", cnt -= 3;
			}
		}
		else
			ret += vec[i] + " ";
	}
	cout << "\"" << ret.substr(0, sz(ret) - (ret[sz(ret) - 2] != '-')) << "\"" << endl;;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	string mannamanamnamanmanam;
	getline(cin, mannamanamnamanmanam);
	while(t--)
		solve();
	return 0;
}
