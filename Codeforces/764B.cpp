#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int fi[MAXN] , se[MAXN], n;
int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> fi[i];

    for (int i = 0; i <= (n + 1)/2 - 1; i++)
        if (!(i % 2))
            swap(fi[i], fi[n - i - 1]);

    for (int i = 0; i < n; i++)
        cout << fi[i]<< " ";

    return 0;
}