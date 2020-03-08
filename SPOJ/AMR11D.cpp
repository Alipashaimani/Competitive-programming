#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a[55],sum,ans,sum1;
    cin >> t;
    while (t--){
        memset(a,0,sizeof(a));
        ans = 0;
        cin >> n ;
        for ( int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        sum=sum1=0;
        for(int i = 0 ; i < n ; i++){
            sum+=i;
            sum1+=a[i];
            if (sum>sum1){
                ans+= sum-sum1;
                sum1 = sum;
            }
        }
        ans += abs(sum1-sum);
        cout << ans << '\n';
    }
    return 0;
}
