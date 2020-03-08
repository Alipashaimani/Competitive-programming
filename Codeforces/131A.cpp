#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
bool iscaps = true;
for (int i = 1; i < s.size(); i++) {
    if (s[i] > 90)
        iscaps = false;
        }
int b, c;
if (iscaps) {
    for ( int i=0;s.size()>=i;i++){
        b=0;c=0;
        if(s[i]>=65 && s[i]<=90){c++;}
        if(s[i]>=97){b++;}
        if (c==1){s[i]+=32;}
        if (b==1){s[i]-=32;}
    }
}
    cout<<s;
}