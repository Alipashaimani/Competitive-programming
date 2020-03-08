#include <iostream>
using namespace std;
int main(){
    int q=0,s=0;
    cin>>q;
char a[q];
    for (int b=0;b<=q-1;b++){
        cin >> a[b];

    }
    for (int b=0;b<=q-1;b++){
        if(a[b]==a[b+1])
            s++;

    }
    cout<<s;

}