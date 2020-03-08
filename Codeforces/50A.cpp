#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if((b*a)%2==0)
    {
        cout<< (b*a/2);
    }
    else{
        cout<< (a*b-1)/2;
    }
    return 0;
}