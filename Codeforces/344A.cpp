#include <iostream>
#include <vector>
using namespace std;
int main(){
    int b,c,q=0,n=00;
    vector<int>a;
    cin>> c;
    for(int i=1;i<=c;i++){
        cin>> b;
        a.push_back(b);
    }
    for(int i=0;i<c;i++)
    {
        if(a[i]!=n)
        {
            q++;
            n=a[i];
        }
    }
    cout<< q;
    return 0;
}