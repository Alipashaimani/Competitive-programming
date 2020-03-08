#include<bits/stdc++.h>
using namespace std;
const int MAXN = 310;
int table[MAXN];
int main(){
    int n;  cin >> n;
    for (int i = 0 ; i < n-1 ; i++){
        cin >> table[i+1];
    }
    int a,b;    cin >> a >> b;
    int ans = 0;
    for (int i = a ; i < b ; i++){
        ans += table[i];
    }
    cout << ans << endl;
}
