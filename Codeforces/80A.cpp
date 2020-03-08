
#include <bits/stdc++.h>
using namespace std;
int main (){
    int Number2,m1,number;
    cin>>Number2>>number;
    Number2++;
    for(int i2 = 0;1000 > i2;i2++){
        m1 = 0;
        for (int i = 2;i <= ( Number2/2 );i++){

            if ( Number2 % i == 0){
                m1=m1+1;

                Number2++;
                break;
            }
        }
        if(m1==0){
            break;
        }
    }
    cout<<(Number2==number?"YES":"NO");
}