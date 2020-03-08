#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int n, a, b;
int arr[MAXN], arr2[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i], arr2[i] = arr[i];

    sort(arr2, arr2 + n);

    for (int i = 0; i < n; i++)
        if (arr[i] != arr2[i]) {
            a = i;
            break;
        }

    for (int i = n; i; i--)
        if (arr[i - 1] != arr2[i - 1]) {
            b = i - 1;
            break;
        }

    for (int i = 0; i <= b - a; i++)
        if (arr[a + i] != arr2[b - i])
            return cout << "no",0;

    cout << "yes" << '\n' << a + 1 << " " << b + 1 << '\n';
    return 0;
}