#include <bits/stdc++.h>
using namespace std;
int main (){
    int n,x;
    cin >> n;
    int arr[n+1];
    bool b[n];
    int k = n-1;
    for (int i = 0; i < n; i++)
        b[i] = false;
    for (int i = 0; i < n; i++){
        cin >> x;
        b[x - 1] = true;
        if (b[k]){
            while (b[k]){
                cout << k+1<<' ';
                k--;
            }
        }
        cout << '\n';
    }
}