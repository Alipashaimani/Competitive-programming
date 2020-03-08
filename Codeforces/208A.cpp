//in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<char>v;
    int r=0;
    bool z = false;
    for (int i = 0; i < s.size() ; i++) {
        if (i < s.size() - 2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 2;
            if (!z)
                v.push_back(' ');
            z = true;
            continue;
        }
        v.push_back(s[i]);
        z = false;
    }
    if ( v[0]==' '){
        r++;
    }
    for ( int i = 0 ; v.size()>i;i++){
        if ( r == 1 ){
            r=0;
            continue;
        }
        cout<<v[i];
    }
}
