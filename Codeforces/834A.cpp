#include <bits/stdc++.h>
using namespace std;

map < char , char > nxt , pas;
char a1,a,b1,b;
long long n;

int main (){
    nxt['^'] = '>',nxt['>'] = 'v',nxt['v'] = '<',nxt['<'] = '^';
    pas['>'] = '^',pas['v'] = '>',pas['<'] = 'v',pas['^'] = '<';

    cin >> a >> b >> n; n %= 4;
    a1 = a , b1 = a;
    while(n--){
        a1 = nxt[a1];
        b1 = pas[b1];
    }
    if((a1 == b && b1 == b) || (a1 != b && b1 != b))
        return cout << "undefined\n" ,0;
    if(a1 == b)
        return cout << "cw\n" ,0;
    cout << "ccw\n", 0;
}