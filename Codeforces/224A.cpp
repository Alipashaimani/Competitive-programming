#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,r1,r2,r3,sum;long long m=1e9+10;  cin>>a>>b>>c;
    r1=c*b/a;
    r2=b*a/c;
    r3=a*c/b;
    for (int i=1 ; i*i <=m ; i++) {
        if (i*i == r1){r1=i;}
        if (i*i == r2){r2=i;}
        if (i*i == r3){r3=i;}
    }
    sum=((r1+r2+r3)*4);
    cout<<sum;

}
