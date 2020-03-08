#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 20;
int n, k, arr[MAXN], maxi = 1, cnt;
long long sum = 0;

int main(){
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int ans = arr[0];

    for (int i = 1; i < n; i++){

        sum += (i - cnt) * 1LL * (arr[i] - arr[i - 1]) * 1LL;

        while (sum > k){
            sum -= arr[i] - arr[cnt];
            cnt++;
        }

        if (maxi < (i - cnt + 1)){
            ans = arr[i];
            maxi = i - cnt + 1;
        }
    }
    return cout << maxi << " " << ans << endl, 0;
}