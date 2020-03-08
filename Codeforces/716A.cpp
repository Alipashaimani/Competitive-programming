#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
int m,n;
int arr[MAXN];
int cnt = 1;
int ans = 1;
int main(){
	cin >> m >> n;
	for ( int i = 0 ; i < m ; i++)
		cin >> arr[i];
	for ( int i = 1 ; i < m ; i++)
		if ( arr[i] - arr[i-1] <= n)
			cnt++;
		else
			cnt = 1;
	cout << cnt << '\n';
	return 0;
}
