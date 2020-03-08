//Young physics//code forces
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c1=0,c2=0,c3=0;
cin>>n;
for ( int i=0 ; n>i;i++ ) {
int a,a2,a3;
cin>> a>>a2>>a3;
c1+=a;
c2+=a2;
c3+=a3;
}
if ( c1== 0 && c2 == 0 && c3 == 0 ) {
cout<<"YES";
}
else
cout<<"NO";

}
