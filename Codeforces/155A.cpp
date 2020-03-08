#include<bits/stdc++.h>
using namespace std;
int main(){
    int MAXN, MINN, a, x, ans = 0;
    cin >> a >> x;
    MAXN = MINN = x;

    for (int i = 1 ; i < a ; i++){
        cin >> x;

        if ( x > MAXN){
            swap (x, MAXN);
            ans++;
        }

        else if ( x < MINN){
            swap(x, MINN);
            ans++;
        }
    }

    cout << ans << '\n';
}