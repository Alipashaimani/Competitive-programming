#include <bits/stdc++.h>
using namespace std;
int sum = 0;
bool zero = 0;
int main(){
    int n;  cin >> n;
    for (int i = 0 ; i < n ; i++){
        int x;  cin >> x;
        if ( x == 0 )
            zero = true;
        else
            sum++;
    }
    if (!zero)
        cout << -1;
    else {
        int cnt = sum/9;
        for (int i = 0 ; i < cnt*9 ; i++)
            cout << 5 ;
        if ( cnt == 0)
            return cout << 0 , 0;
        for (int i = 0 ; i < n - sum ; i++)
            cout << 0;
    }
}
