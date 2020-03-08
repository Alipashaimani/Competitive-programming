#include <bits/stdc++.h>
using namespace std;
int main(){
int a, b, c25 = 0, c50 = 0, c100=0, d25=0 , d50=0 , d100=0;
cin >> a;
for( int i = 0 ; i < a; i++ ) {
    c25 = 0; c50 = 0; c100=0;
    cin>>b;
    if ( b == 25 ){
        d25++;
        continue;
    }
    else if ( b == 50 )
        c50=1;
    else if ( b == 100 )
        c100=1;

 if ( c50 <= d25 && c50 >= 1 && d25 >= 1 ){
        d25--;
        d50++;
        continue;
        //cout<<"if 1"<<endl;
    }
    else if ( c100 <= d50 && c100 <= d25 && c100 >= 1 && d25 >= 1 && d50 >= 1   ){
        d100++;
        d50--;
        d25--;
        continue;
        //cout<<"if 2"<<endl;
    }
    else if ( 3*c100 <= d25 && c100 >= 1 && d25 >= 3 ){
        d100++;
        d25-=3;
        continue;
        //cout<<"if 3"<<endl;
    }
 else {
     cout<<"NO";
     return 0 ;
 }
}
 cout<<"YES";
return 0;
 }
