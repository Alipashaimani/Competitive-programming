#include<bits/stdc++.h>
using namespace std;
long long a, b, y[150000 + 10], cnt = 0;
bool flag = 0;
int main(){
    cin >> a >> a >> b;
    for ( int i = 0 ; i < a+1 ; i++){
        cin >> y[i];
    }
    int x = 0;
    for ( int i = 0 ; i < a ; i++)
        x+= ((__builtin_popcount(y[a] ^ y[i])) <= b);
    cout << x << '\n';
}
