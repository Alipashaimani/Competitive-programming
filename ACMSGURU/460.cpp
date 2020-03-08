
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
	int n;
	cin>>n;
	rep(i, n){
		string s;
		cin>>s;
		if(s[s.size()-1]=='x' || s[s.size()-1]=='o' || s[s.size()-1]=='s' || (s[s.size()-1]=='h' && s[s.size()-2]=='c'))
			cout<<s<<"es"<<endl;
		else if(s[s.size()-1]=='e' && s[s.size()-2]=='f'){
			s[s.size()-2]='v';
			s+='s';
			cout<<s<<endl;
		}
		else if(s[s.size()-1]=='f'){
			s[s.size()-1]='v';
			s+="es";
			cout<<s<<endl;
		}
		else if(s[s.size()-1]=='y'){
			s[s.size()-1]='i';
			s+="es";
			cout<<s<<endl;
		}
		else
			cout<<s<<'s'<<endl;
	}
	return 0;
}
