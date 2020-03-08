#include <iostream>
using namespace std;
int main(){
    long double n;
    cin>>n;
    if(n<=127){
        cout<<"byte";
        return 0;
    }

    else if(n<=32767){
        cout<<"short";
        return 0;
    }

    else if(n<=2147483647){
        cout<<"int";
        return 0;
    }

    else if(n<=9223372036854775807){
        cout<<"long";
        return 0;
    }

    else {
        cout<<"BigInteger";
        return 0;
    }
}