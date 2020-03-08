#include <iostream>
using namespace std;
int main(){
    string a,b;
    int x,y;
    bool a1=0;
    cin>> a>>b;
    for(int i=0;i<a.size();i++)
    {
    x=a[i];
    y=b[i];
    if(x>90){
        x-=32;
    }
    if(y>90)
    {
        y-=32;
    }
    if(x>y)
    {
     cout<< "1";
     a1=1;
     break;
    }
    else if(x<y)
    {
        cout<< "-1";
        a1=1;
        break;

    }
    }
    if(a1==0)
    {
        cout<< "0";
    }
    return 0;
}