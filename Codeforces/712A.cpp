#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
int main (){
    cin >> n ;

    for (int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0 ; i < n - 1 ; i++){
        cout << a[i] + a[i + 1] << " " ;
    }
    cout << a[n - 1] << '\n' ;
}