#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000 + 100;

int n , arr[MAXN];

int main() {
    cin >> n;
    for(int i = 0 ; i < n ;i++)
        cin >> arr[i];
    cout << n << '\n';
    for (int i = 0 ; i < n ; i++){
        int x = i;
        for ( int j = i ; j < n ; j++)
            arr[j] < arr[x]? x = j :x = x;
        cout << x << " " << i << endl;
        swap(arr[i] , arr[x]);
    }
    return 0;
}
