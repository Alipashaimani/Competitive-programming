//alipasha
#include<bits/stdc++.h>
using namespace std;
string s;
set<string>ss;
int main(){
    cin >> s;
    for ( int i = 0 ; i < s.size() ; i++){
        rotate(s.begin(),s.begin()+1,s.end());
        ss.insert(s);
    }
    cout << ss.size() << '\n';
}