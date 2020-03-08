//football 43-A
#include <bits/stdc++.h>
using namespace std;
int n,r,m;
string s,s2,st;
int main() {
    cin>>n>>st;
    s=st;
    r++;
    for (int i=1 ; i < n ; i++){
        cin>>st;
        if (st == s)
            r++;
        else {
            s2=st;
            m++;
        }
    }
    if (r > m)
        cout<<s;
    else
        cout<<s2;
}