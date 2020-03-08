#include <bits/stdc++.h>

using namespace std;

bool who[600];
int pos[600];
int n, m, p[10];
int k;

void fill_who(int id){
	for(int i = 0; i < m; i++)
		if(id - p[i] >= 0 and !who[id - p[i]])
			who[id] = true;
	return;
}

void print(bool w){
	cout << (w ? "FIRST" : "SECOND") << " PLAYER MUST WIN\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	p[0] = 1;
	cin >> k;
	while(k--){
		cin >> n >> m;
		m++;
		for(int i = 1; i < m; i++)
			cin >> p[i];
		memset(who, false, sizeof who);
		memset(pos, -1, sizeof pos);
		who[0] = true;
		for(int i = 1; i < 10; i++)
			fill_who(i);
		int num = 0;
		for(int i = 1; i < 10; i++)
			num = num * 2 + who[i];
		pos[num] = 9;
		for(int i = 10; i < 600; i++){
			fill_who(i);
			num = (num * 2 + who[i]) % 512;
			if(pos[num] != -1){
				if(n <= i)
					print(who[n]);
				else
					print(who[((n - pos[num]) % (i - pos[num])) + pos[num]]);
				goto bokhor;
			}
			pos[num] = i;
		}
bokhor:;
	}
	return 0;
}
