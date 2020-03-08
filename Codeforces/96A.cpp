#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int m,r;
    cin>>s;
    m=s.find("1111111");
    r=s.find("0000000");
    cout<<( m>=0 || r>=0 ? "YES" : "NO");
    return 0;
  }