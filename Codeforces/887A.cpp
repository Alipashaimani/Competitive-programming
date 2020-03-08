#include <bits/stdc++.h>
using namespace std ;

int cnt;
bool flag;

int main(){

    string s;   cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            flag = 1;
        if(s[i] == '0' && flag)
            cnt++;
    }
    if(cnt >= 6)
        return cout << "yes\n", 0;
    return cout << "no\n", 0;
}