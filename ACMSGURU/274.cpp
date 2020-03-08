#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

string s;
int n;

bool is_letter(int st, int en){
	if(en - st != 1)
		return false;
	return (s[st] >= 'a' and s[st] <= 'z') or (s[st] >= 'A' and s[st] <= 'Z');
}

bool is_symbol(int st, int en){
	if(en - st != 1)
		return false;
	return is_letter(st, en) or (s[st] >= '0' and s[st] <= '9') or s[st] == '-' or s[st] == '_';
}

bool is_word(int st, int en){
	if(st >= en)
		return false;
	if(en - st == 1)
		return is_symbol(st, en);
	return is_symbol(st, st + 1) and is_word(st + 1, en);
}

bool is_prefix(int st, int en){
	if(st >= en)
		return false;
	if(count(s.begin() + st, s.begin() + en, '.') == 0)
		return is_word(st, en);
	int id = st;
	while(s[id] != '.')
		id++;
	return is_word(st, id) and is_prefix(id + 1, en);
}

bool is_domain(int st, int en){
	if(en - st != 2 and en - st != 3)
		return false;
	if((!is_letter(st, st + 1)) or !is_letter(st + 1, st + 2))
		return false;
	if(en - st == 2)
		return true;
	return is_letter(st + 2, st + 3);
}

bool is_suffix(int st, int en){
	if(st >= en)
		return false;
	if(count(s.begin() + st, s.begin() + en, '.') == 0)
		return false;
	int id = en - 1;
	while(s[id] != '.')
		id--;
	return is_prefix(st, id) and is_domain(id + 1, en);
}

bool is_address(int st, int en){
	if(st >= en or count(s.begin() + st, s.begin() + en, '@') != 1)
		return false;
	int id = find(s.begin() + st, s.begin() + en, '@') - s.begin() - st;
	return is_prefix(st, id) and is_suffix(id + 1, en);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	getline(cin, s);
	while(n--){
		getline(cin, s);
		cout << (is_address(0, sz(s)) ? "YES\n" : "NO\n");
	}
	return 0;
}
