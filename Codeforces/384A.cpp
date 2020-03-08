#include <bits/stdc++.h>
using namespace  std;
const int MAXN = 1000;
int arr[MAXN];
int ans = 0;
int main(){
    int n;  cin >> n;
    cout << ((n*n)+1)/2 << endl;
    for ( int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < n ; j++){
            if (!(i+j & 1))
                cout << 'C';
            else
                cout << '.';
        }
        cout << endl;
    }
}