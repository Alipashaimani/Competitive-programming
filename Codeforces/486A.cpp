//in the name of God
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b=0,b2=0,c=0,c2=0,m=0;
    cin>>a;
    if ( a % 2 == 0 ){
        c=((a-2)/2)+1;
        c2=(((a-1)-1)/2)+1;
        b=((a+2)/2)*c;
        b2=(((a-1)+1)/2)*c2;
        m=b-b2;
    }
    else {
        c=((a-1)/2)+1;
        c2=(((a-1)-2)/2)+1;
        b=(a+1)/2*c;
        b2=(((a-1)+2)/2)*c2;
        m=b2-b;
    }
    cout<<m;
}

