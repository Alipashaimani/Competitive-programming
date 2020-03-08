//InTheNameOfGod
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long min1 = ( a + b + c ) / 3;
    long long min2 = min ( a + b , min ( a + c, b + c ) );
                    cout << min ( min1 , min2 );

                    }