#include <bits/stdc++.h>
using namespace std;
int main() {
    int c=0;
    string a,b="hello";
    cin>>a;
    for(int i=0;a.size()>i;i++){
        if ( a[i]==b[c])c++;
    }
    cout<<(c==5?"YES":"NO");
}
