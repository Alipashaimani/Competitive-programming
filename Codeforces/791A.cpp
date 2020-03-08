#include <iostream>
using namespace std;
int n,m,x;
int main(){
	cin >> n >> m;
	while (n <= m) {
		++x;
		n *= 3;
		m *= 2;
	}
	cout << x;
}