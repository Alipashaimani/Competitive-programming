#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  int a,x,y=0,z=0,Q=0;
  cin>>a;
  string A;
  for(int i=1;i<=a;i++)
  {
    cin >>x>>y>> z;
    if((x+y+z)>=2)
    {
      Q++;
    }
  }
  cout<< Q;



}