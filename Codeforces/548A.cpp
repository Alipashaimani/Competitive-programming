#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a;
	cin >> s >> a;
	if(s.size() % a != 0){
		cout<<"NO";
		return 0;
	}

	for(int i = 0; i < s.size() ;i += (s.size() / a)){
		bool flag = 1;
		for(int j = 0 ;(j + 1 < (s.size() / a)); j++){
			if(s[i + j] != s[(s.size() / a) - j + i - 1]){
				flag = 0;
				break;
			}
		}

		if(flag == 0){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}