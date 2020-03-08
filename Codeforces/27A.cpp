#include <bits/stdc++.h>
using namespace std;
bool b[3100];
int main(){
int a;
cin>>a;
for ( int i = 0 ; a > i ; i++){
	int x ;
	cin >>x;
	b[x]=true;
}
for ( int i = 1 ; ; i++){
	if ( b[i]==false){
		cout<<i;
		return 0;
	}
}
	}