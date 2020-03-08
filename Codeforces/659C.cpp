#include<bits/stdc++.h>
using namespace std;
long long n,m;
set<long long> s,t;
int main(){
	cin>> n >> m;
	for (int i = 0; i < n; i++){
		long long x;	cin>>x;
		s.insert(x);
	}
	for (int i = 1;i<=m; i++)
		if (!s.count(i)){
			m-=i;
			t.insert(i);
		}
	cout<< t.size() <<'\n';
	for (auto i:t)
		cout<<i<<' ';
}
