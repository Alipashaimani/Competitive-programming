#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,s2,s3;
    cin >> s >> s2 >> s3;
    sort ( s3.begin(),s3.end());
    s = s+s2;
    sort ( s.begin(),s.end());
    cout<<(s==s3?"YES":"NO");
}