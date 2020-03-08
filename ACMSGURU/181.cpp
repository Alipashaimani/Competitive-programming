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

const int maxm=1e3+100;
ll arr[maxm];
int period, begin;

int main(){
	ios_base::sync_with_stdio(false);
	ll A, alp, bet, gam, m, k;
	cin>>A>>alp>>bet>>gam>>m>>k;
	if(k==0){
		cout<<A<<endl;
		return 0;
	}
	arr[0]=A%m;
	FOR(i, 1, m){
		arr[i]=gam+arr[i-1]*(bet+(arr[i-1]*alp));
		arr[i]%=m;
	}
	FOR(i, 0, m){
		FOR(j, i+1, m){
			if(arr[i]==arr[j]){
				period=j-i;
				begin=i;
				break;
			}
		}
	}
	if(k<=m)
		cout<<arr[k]<<endl;
	else{
		k-=begin;
		cout<<arr[begin+(k%period)]<<endl;
	}
	return 0;
}
