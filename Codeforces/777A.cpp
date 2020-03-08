#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[6][3]={{0, 1, 2}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}, {0, 2, 1}};

int main() {
    cin >> n >> x;
    cout << arr[n%6][x];
    return 0;
}
