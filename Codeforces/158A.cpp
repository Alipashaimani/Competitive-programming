#include<bits/stdc++.h>
using namespace std;
int main(){
    int s=0,n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=n-1;i>=0;i--)
        if(a[i]>=(a[k-1]) && a[i]!=0){ s++;}
    cout<<s;
}