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

const int MAXn=7e4;
ll a[MAXn];
ll ans=0;

void Sort(int, int);
void Merge(int, int, int);

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(i, n)
		cin>>a[i];
	Sort(0, n);
	cout<<ans<<endl;
	return 0;
}

void Sort(int s, int e){
	if(s+2==e && a[s]>a[s+1]){
		swap(a[s], a[s+1]);
		ans++;
	}
	if(s>=e-2)
		return;
	int mid=(s+e)/2;
	Sort(s, mid);
	Sort(mid, e);
	Merge(s, mid, e);
}

void Merge(int s, int mid, int e){
	int p=s;
	int q=mid;
	int re=0;
	vector <int> temp;
	while(p<mid || q<e){
		if(q==e){
			ans+=re;
			temp.pb(a[p++]);
		}
		else if(p==mid){
			re++;
			temp.pb(a[q++]);
		}
		else if(a[p]<=a[q]){
			ans+=re;
			temp.pb(a[p++]);
		}
		else{
			re++;
			temp.pb(a[q++]);
		}
	}
	rep(i, temp.size())
		a[i+s]=temp[i];
}





