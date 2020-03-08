#include <bits/stdc++.h>
using namespace std;
map<string,long long>m;
string fiter(string s, long long i){
    string ss= "";
    for (long long k = i ;k < s.size() ; k++){
        ss+=s[k];
    }
    return ss;
}
long long ans(string s){
    if (m.count(s))
        return m[s];

    if (s.size() <= 1)
        return 1;
    if (s[1] == '0'){
        m[s] = ans(fiter(s,2));
        return m[s];
    }
    if (s.size() >= 3 && s[2] == '0'){
        m[s] = ans(fiter(s,1));
        return m[s];
    }
    if (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6')){
        m[s] = ans(fiter(s,1)) + ans(fiter(s,2));
        return m[s];
    }
    m[s] = ans(fiter(s,1));
    return m[s];
}
int main(){
    string n ;
    while(1){
        cin >> n;
        if (n == "0")
            return 0;
        cout  <<  ans(n) << '\n';
    }
}


