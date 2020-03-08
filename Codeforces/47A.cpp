#include <bits/stdc++.h>
using namespace std;
set<int>a;
int main(){
    for ( int i = 1 ; i < 500 ; i++){
        a.insert((i*(i+1))/2);
    }
    int n;
    cin >> n;
    cout << (a.count(n)?"YES":"NO") << '\n';
}