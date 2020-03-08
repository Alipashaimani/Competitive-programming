#include <bits/stdc++.h>
using namespace std;

int check(int A, int B, int C) {
    int move = 1, a = A, b = 0, p;
    while(a != C && b != C) {
        
        p = min(a, B-b);
        b += p; a -= p;
        move++;
        
        if(a == C || b == C)
            break;
        
        if(b==B){
            b = 0;
            move++;
        }
        else if(a==0){
            a = A;
            move++;
        }
    }
    return move;
}

int main() {
    int a, b, c, t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        
        if(c > a && c > b)
            cout << -1 << '\n';
        
        else if(!c)
            cout << 0 << '\n';
        
        else if(c == a || c == b)
            cout << 1 << '\n';
        
        else if(c % __gcd(a, b))
            cout << -1 << '\n';
        
        else
            cout << min(check(a, b, c), check(b, a, c)) << '\n';
    }
    return 0;
}
