//Be Name Khoda
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;
string s, s2;

ll pw(int a,int b){
    if ( b == 1)
        return a;
    ll d = pw(a, b/2);
    d = (1LL * d * d);

    if ( b & 1)
        d = ( 1LL * d * a);

    return d;
}

void change(ll x, string &y){
    y = "";
    while(x){
        if(x % 2)
            y = '1' + y;
        else
            y = '0' + y;
        x /= 2;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin >> a >> b;

    change(a,s);    change(b,s2);

    while(s.size() < s2.size())
        s = '0' + s;

    for (int i = 0; i < s.size(); i++){
        if(s[i] != s2[i])
            return cout << pw(2, s.size() - i) - 1 << '\n', 0;
    }
    return cout << 0 << '\n', 0;
}