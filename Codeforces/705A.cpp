#include <bits/stdc++.h>
using namespace std;

int n;
string s[4] = {"I hate","I love","that","it"};

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (i % 2)
			cout << s[0] << " " << s[2] << " ";
		else
			cout << s[1] << " " << s[2] << " ";
	}

	if (n % 2)
			cout << s[0] << " " << s[3];
		else
			cout << s[1] << " " << s[3];
	return 0;
}