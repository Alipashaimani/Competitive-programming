#include <bits/stdc++.h>
using namespace std;
int fs,sf,n;
char c1, c2;
int main(){
    cin >> n >> c1;
    for (int i = 1; i < n; i++){
        cin >> c2;
        if (c2 != c1){
            if (c2 == 'F')
                sf++;
            else
                fs++;
        }
        c1 = c2;
    }
    if ( sf > fs)
        cout << "YES\n";
    else
        cout << "NO\n";
}
