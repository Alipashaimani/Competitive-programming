#include <bits/stdc++.h>
using namespace std ;

int a;
int main(){
    cin >> a;
    if (a % 2 == 0){
        cout << a/2 << '\n';
        for(int i = 0; i < a/2; i++){
            cout << "2 ";
        }
    }
    else{

		cout << a/2 << '\n';

		for(int i = 0 ;i < a/2 - 1; i++)
        cout << "2 ";

		cout << "3 ";
    }
	cout << '\n';
	return 0;
}
