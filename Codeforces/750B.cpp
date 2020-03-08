#include <bits/stdc++.h>
using namespace std;
int pos , n;
int main(){
	cin >> n;
	while (n--){
		int val;
		string s;
		cin >> val >> s;
		if (s[0] == 'N'){
			if (pos - val < 0)
				return cout << "NO\n",0;
			else
				pos -= val;
		}
		else if (s[0] == 'S'){
			if (pos + val > 20000)
				return cout << "NO\n",0;
			else
				pos += val;
		}
		else if (pos == 0 || pos == 20000)
			return cout << "NO\n",0;
	}
    return cout << (pos == 0 ? "YES\n" : "NO\n") << endl,0;
}
