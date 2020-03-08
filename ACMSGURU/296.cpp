#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int main(){
	ios_base::sync_with_stdio(false);
	int n, p;
	string s;
	cin>>s>>p;
	n=s.size();
	vector <int> a;
	rep(i, n)
		a.pb(s[i]-48);
	while(a.size()>n-p){
		bool found=false;
		rep(j, a.size()-1){
			if(a[j]<a[j+1]){
				found=true;
				a.erase(a.begin()+j);
				break;
			}
		}
		if(!found)
			a.erase(a.end()-1);
	}
	for(int i=0; i<a.size(); i++)
		cout<<a[i];
	cout<<endl;

	return 0;
}
