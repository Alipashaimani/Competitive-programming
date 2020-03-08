#include <iostream>
using namespace std;
int main(){
 int s,a=0,b=0,m=0,maxn;
 cin>>s;
 for (int i=0;s>i;i++){
     cin>>a>>b;
     m=m-a+b;
     maxn=max(maxn,m);
 }
 cout<<maxn;
}