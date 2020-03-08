
#include <iostream>

using namespace std;

int main() {
    int a,b1,b2,m=0;
    cin>>a;
    for(int i=0;a>i;i++)
    {
        cin>>b1>>b2;
        b2=b2-b1;
        if (b2>=2)
            m++;
    }
    cout<<m;
}