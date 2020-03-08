#include <bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
cin >> a >> b >> c;
int ans = 0;
while(a>0 && b > 1 && c > 3){
  ans += 7;
  a-=1;
  b-=2;
  c-=4;
      }
cout << ans << endl;
}
