#include <bits/stdc++.h>
using namespace std;
int a[5],b[5]={1},j=0;
int main(){
    int m=0,r=0,rr=0,u=0,f=0;
    for ( int i = 0 ; 5 > i ; i++){
        cin>>a[i];
        m+=a[i];
    }
    sort(a,a+5);
    for ( int i = 0 ; 4 > i ; i++){
        if ( a[i]==a[i+1]){
            b[j]++;
        }
        else {
            j++;
            b[j]++;
        }
    }
    for ( int i = 0 ; 5 > i ; i++){
        if ( b[i]==1){rr++;}
        else if (b[i]>=2){
            if ( b[i]==5){rr+=5;u=5;}
            if ( b[i]==4){rr+=4;u=4;}
            if ( b[i]==3){rr+=3;u=3;}
            if ( b[i]==2){rr+=2;u=2;}

            if ( b[i]==2 || b[i]==3){
                for ( int t = 0 ; 5 > t ; t++){
                    if ( t >=rr || rr-u>t ){
                        r+=a[t];
                    }
                }
            }
            else if ( b[i]==4 || b[i]==5){
                for ( int t = 0 ; 5 > t ; t++){
                    if ( t >=rr || rr-u>t ){
                        r+=a[t];
                    }
                }
                r+=((b[i]-3)*a[rr-1]);
            }
            m=min(m,r);
            r=0;f=0;
        }
    }
    cout<<m;
}