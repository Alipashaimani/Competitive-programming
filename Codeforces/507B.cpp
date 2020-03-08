#include<bits/stdc++.h>
using namespace std;
long long r, a, b, c, d;
int main(){
	cin >> r >> a >> b >> c >> d;
	long double dis = sqrt((d - b) * (d - b) + (c - a) * (c - a));
	return cout << ceil(dis/(2*r)) << endl,0;
}
