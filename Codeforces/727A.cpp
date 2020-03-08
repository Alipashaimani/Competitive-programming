#include<bits/stdc++.h>
using namespace std;
long long arr[10000000],a, b, cnt = 0;;
int main() {
    cin >> a >> b;
    arr[cnt] = b;
    while (b) {
        if (b == a) {
            break;
        }
        if (b % 10 == 1) {
            b /= 10;
            ++cnt;
            arr[cnt] = b;
        }
        else if (!((b % 10) % 2)) {
            b /= 2;
            ++cnt;
            arr[cnt] = b;
        }
        else {
            b = 0;
            break;
        }
    }
    if (!b) {
        cout <<  "NO\n";
        return 0;
    }
    cout <<"YES\n"<< cnt + 1 << '\n';
    for (long long i = cnt; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    return 0;
}