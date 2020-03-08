//InTheNameOfGod
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    int bus = 0, cnt = 0;
    cin >> a >> b;

    for ( int i = 0 ; i < a ; i++ ) {
        cin >> c;
        cnt += c;
        if ( cnt > b ) {
            cnt = c;
            bus ++;
        }
    }
    cout << ++bus;
}
