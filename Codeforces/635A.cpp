#include<bits/stdc++.h>
using namespace std;
int r,n,c,k,ans = 0;
int arr[1000][1000];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> n >> c >> k;
    for ( int i = 1 ; i <= c ; i++){
        int x,y;
        cin >> x >> y;
        arr[x][y] = 1;
    }
    for ( int i = 1 ; i <= r ; i++){
        for  ( int j = 1 ; j <= n ; j++){
            for ( int i2 = i ; i2 <= r ; i2++){
                for ( int j2 = j ; j2 <= n ; j2++){
                    int cnt = 0;
                    for ( int t = i ; t <= i2 ; t++){
                        for ( int t2 = j ; t2 <= j2 ; t2++){
                            cnt += arr[t][t2];
                        }
                    }
                    ans+= ( cnt >= k);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
