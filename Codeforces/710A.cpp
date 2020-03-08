#include <bits/stdc++.h>
using namespace std;
int main(){
    int a; char c;
    cin >> c >> a;
    if ( c == 'a' || c == 'h'){
        if ( a == 1 || a == 8){
            cout << "3\n";
            return 0;
        }
        cout << "5\n";
        return 0;
    }
    if ( a == 1 || a == 8){
        cout << "5\n";
        return 0;
    }
    cout <<"8\n";
    return 0;
}