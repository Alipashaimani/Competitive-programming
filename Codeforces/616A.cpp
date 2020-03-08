#include <bits/stdc++.h>
using namespace std;
int main(){
	string s,s2;
	cin>>s>>s2;
	if ( s.size()>s2.size()){
		reverse ( s2.begin(),s2.end());
		while ( s.size()>s2.size())
		s2.push_back('0');
		reverse ( s2.begin(),s2.end());
	}
	else if ( s2.size()>s.size()){
		reverse ( s.begin(),s.end());
				while ( s2.size()>s.size())
				s.push_back('0');
				reverse ( s.begin(),s.end());
	}
	for ( int i = 0 ; s.size()> i ; i++){
		if ( s[i]>s2[i]){
			cout<<">";
			return 0;
		}
		else if ( s2[i]>s[i]){
			cout<<"<";
			return 0 ;
		}
	}
	cout<<"=";
	}