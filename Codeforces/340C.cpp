#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
long long arr[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n;    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    long long cnt = 0;

    for(int i = 1; i <= n; i++)
        cnt -= arr[i - 1] * (n - 2 * (i - 1) - 1);

    cnt *= 2;

    for(int i = 0; i < n; i++)
        cnt += arr[i];

    long long gcd = __gcd(cnt, n);

    cout << cnt / gcd << " " << n / gcd << '\n';
    return 0;
}

