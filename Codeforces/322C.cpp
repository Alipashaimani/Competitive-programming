#include <bits/stdc++.h>
using namespace std;

long long a, b, c, ans, x, y, xx, yy, hx, hy;
string s;

int main(){
    cin >> a >> b >> s;
    for (int i = 0 ; i < s.size() ; i++){
        if(s[i]=='U')
            y++;
        if(s[i]=='D')
            y--;
        if(s[i]=='R')
            x++;
        if(s[i]=='L')
            x--;
    }

    for (int i = 0 ; i < s.size(); i++){
        hx = a - xx;
        hy = b - yy;

        if(!y && !hy && !x && !hx)
            return cout << "Yes\n", 0;

        if(!y && x && !hy && !(hx%x) && (hx/x)>=0)
            return cout << "Yes\n", 0;

        if(!x && y && !hx && !(hy%y) && (hy/y)>=0)
            return cout << "Yes\n", 0;

        if(x && y && !(hx%x) && !(hy%y) && (hx/x)==(hy/y) && (hx/x)>=0)
            return cout << "Yes\n", 0;

        if(s[i]=='U')
            yy++;
        if(s[i]=='D')
            yy--;
        if(s[i]=='R')
            xx++;
        if(s[i]=='L')
            xx--;
    }

    return cout << "No\n" ,0;
}
