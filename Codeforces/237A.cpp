#include<bits/stdc++.h>
using namespace std;
int a;
int ans = 1,cnt = 1;
const int MAXN = 1e5 + 100;
pair<int,int>per[MAXN];
int main(){
	cin >> a;
	for (int i = 0 ; i < a ; i++)
		cin >> per[i].first >> per[i].second;
	sort(per,per+a);
	for ( int i = 1 ; i < a ; i++)
		if ( per[i].first == per[i-1].first && per[i].second == per[i-1].second )
			cnt++;
		else{
			ans = max(cnt,ans);
			cnt = 1;
		}
	ans = max(ans,cnt);
cout << ans;
}
