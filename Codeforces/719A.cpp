#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, a[100];
  cin >> n;
  for(int i = 1 ; i<=n ; i++)
	  cin>>a[i];
  if(a[n]==15)
	  cout<<"DOWN";

  else if(a[n]==0)
	  cout<<"UP";

  else if(n==1)
	  cout<<-1;
  else
	  cout<<((a[n]>a[n-1])?"UP":"DOWN");
  return 0;

}
