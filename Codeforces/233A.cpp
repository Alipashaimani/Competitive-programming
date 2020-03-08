#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int main(){
    int n;
    cin >> n;
    if ( n % 2 == 0){
        for (int i = n ; i ; i--)
        cout << i << " ";
    }else
        cout << -1 << endl;
    return 0;
}
