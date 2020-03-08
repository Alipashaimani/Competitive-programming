#include <bits/stdc++.h>
using namespace std;
int main(){
int a;
cin >> a;
if ( a == 1 or a == 2)
  return  cout << 1 << "\n" << 1 << endl,0;
if ( a == 3)
  return cout << 2 << '\n' << 1 << " " << 3 << endl , 0;
cout << a << endl;
for (int i = a ; i ; i--){
  if ( i & 1 )
  cout << i << " ";
    }
for (int i =  a ; i ; i--){
  if ( !(i&1))
  cout << i <<" ";
    }
}
