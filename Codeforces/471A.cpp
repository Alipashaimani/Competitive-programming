#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int m,n;
int arr[MAXN];
bool flag = 0;
bool check = true;
int main(){
	for ( int i = 0 ; i < 6 ; i++){
		int x;
		cin >> x;
		arr[x]++;
	}
	for ( int i = 1 ; i <= 10 ; i++){
		if (arr[i] >= 4 ){
			arr[i] -= 4;
			flag = true;
		}
	}
	for ( int i = 1 ; i <= 10 ; i++){
		if ( arr[i] == 1 && check ){
			m = i ;
			check = false ;
		}
		if ( arr[i] == 1 && !check )
			n = i;
		if ( arr[i] == 2){
			m=n=i;
			break;
		}
	}

	if (!flag)
		return cout << "Alien\n" , 0;
	if ( m == n)
		return cout << "Elephant\n" , 0;
	if ( m > n || n > m )
		return cout << "Bear\n" , 0;

}
