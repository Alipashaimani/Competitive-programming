#include<bits/stdc++.h>

using namespace std;
const int MAXN = 5e5+100;
int n,k;
int arr[MAXN];
bool check(int mid,int k){
	for (int i = 0 ; i < n ; i++){
		if ((arr[i] + (mid-1)) / mid <= k)
			k -= ((arr[i] + (mid-1))/mid);
		else 
			return false;
	}
	return true;

}
int main(){
	while(true){

	cin >> n >> k;

	if ( n == -1 && k == -1 )
		break;

	for ( int i = 0 ; i < n ; i++)
		cin >> arr[i];

	 int l = 0 ,r = 2e6+100;

        while(l+1<r){
            int mid = (l+r)/2;
            if (check(mid,k))
                r = mid;
            else
                l = mid;
        }
        cout << r << '\n';
    }
}

