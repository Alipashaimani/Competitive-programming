#include<iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n*n/2;i++)
        cout<<i+1<<" "<<n*n-i<<" ";
    cout<<endl;
}