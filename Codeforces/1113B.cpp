#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e4 + 10;
int n,a[MAXN],ans,s;

int32_t main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i],s+=a[i];
	ans=s;
	sort(a,a+n);
	for (int i = 1; i < n; i++)
		for (int j = 2; j <= a[i]; j++)
			if (a[i]%j==0)
				ans=min(ans,s-a[i]+a[i]/j-a[0]+a[0]*j);
	cout << ans << endl;
}
