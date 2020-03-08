#include<bits/stdc++.h>
using namespace std;
long long a, b, y[150000 + 10], minn, minX = 0 ;
bool flag = 0;
int main(){
    fill ( y , y+b , 0);
    cin >> a >> b;
    //a=b=150000;
    for ( long long i = 0 ; i < a ; i++){
        int x;
        cin >> x;
        y[i+1] = y[i] + x;
    }

    for ( long long i = 0 ; i <= a-b ; i++){
        long long cnt = 0;
        cnt = y[b+i] - y[i];
        if ( flag == 0){
            minn = cnt;
            flag = 1;
        }
        if ( cnt <= minn ){
            minn = cnt;
            minX = (i+1);
        }

    }
    cout << minX << '\n' ;
}