#include<bits/stdc++.h>
using namespace std;
long long a, b, y[150000 + 10], cnt = 0;
bool flag = 0;
int main(){
    cin >> a >> b;
    for ( int i = 0 ; i < a ; i++){
        int x,y;
        cin >> x >> y;
        cnt += ((y-x)+1);
    }

    cout << ((b-(cnt % b))==b?0:(b-(cnt % b))) << '\n';
}