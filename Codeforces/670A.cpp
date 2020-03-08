#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;	cin >> n;
    return cout << n/7 * 2 + (n%7 > 5) << " "<< n/7 * 2 + min(2, n%7) << endl,0;
}