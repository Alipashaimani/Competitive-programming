#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
long double arr[MAXN];
int main(){
int m,n;
cin >> n >> m;
for ( int i = 0 ; i < n ; i++){
	cin >> arr[i];
}
sort(arr,arr+n);
long double maxr = 0;
for ( int i = 0 ; i < n - 1 ; i++)
	maxr = max(maxr ,( arr[i+1] - arr[i]));

maxr = max(maxr ,2 * max(arr[0],m-arr[n-1]));
maxr/=2.0;
return cout << fixed << setprecision(10) << maxr << '\n' , 0;
}
