#include<bits/stdc++.h>
using namespace std;
int main(){
    int r=0;
    string s;
    getline(cin,s);
    vector<char>c;
    for ( int i = 0 ; s.size()>i;i++){
        if ( s[i]>='a' && s[i]<='z'){
            c.push_back(s[i]);
        }
    }
    sort ( c.begin(),c.end());
    for ( int i = 0 ; c.size()>i;i++){
        if ( c[i]!=c[i+1]){
            r++;
        }
    }
    cout<<r;
}
