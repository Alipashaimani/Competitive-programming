#include <bits/stdc++.h>
using namespace std;
int n ,arr[100000],c;
bool check(int a){
    int x = arr[0],cnt = 1;
    for ( int i = 1 ; i < n ; i++){
        if ( arr[i]-x >= a){
            cnt++;
            x = arr[i];
        }
    }
    return cnt >= c;
}
int main(){
    int m;
    cin >> m;
    for ( int j = 0 ; j < m ; j++){
        cin >> n >> c;
        
        for ( int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int l = 0 ,r = 1e9+1;
        while(l+1<r){
            int mid = ( l + r) /2;
            if (!check(mid))
                r = mid;
            else
                l = mid;
        }
        cout << l << '\n';
    }
}
