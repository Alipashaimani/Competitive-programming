#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a, b, cnt = 0;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector <int> p[3];
	for(int i = 0; i < s.size(); i++)
		p[s[i] - 48].push_back(i);

	if(a + b > n){
		cout << -1 << endl;
		return 0;
	}

	a = (int)p[0].size() - a;
	b = (int)p[1].size() - b;
	
	while(a > 0){
		cnt ++;
		if(b < 0){
			s[p[0].back()] = '1';
			b ++;
			a --;
			p[1].push_back(p[0].back());
			p[0].pop_back();
		}
		else{
			s[p[0].back()] = '2';
			a --;
			p[2].push_back(p[0].back());
			p[0].pop_back();
		}
	}
	while(a < 0){
		cnt ++;
		if(b > 0){
			s[p[1].back()] = '0';
			b --;
			a ++;
			p[0].push_back(p[1].back());
			p[1].pop_back();
		}
		else{
			s[p[2].back()] = '0';
			a ++;
			p[0].push_back(p[2].back());
			p[2].pop_back();
		}
	}
	while(b > 0){
		cnt ++;
		s[p[1].back()] = '2';
		b --;
		p[2].push_back(p[1].back());
		p[1].pop_back();
	}
	while(b < 0){
		cnt ++;
		s[p[2].back()] = '1';
		b ++;
		p[1].push_back(p[2].back());
		p[2].pop_back();
	}
	cout << cnt << endl;
	cout << s << endl;
	return 0;
}
