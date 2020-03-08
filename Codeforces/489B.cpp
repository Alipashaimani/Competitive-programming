#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 110;
int boy[MAXN];
int girl[MAXN];
int ans = 0;
int main (){
    int n;  cin >> n;
    for (int i = 0 ; i < n ; i++)
    cin >> boy[i];
    int m;  cin >> m;
    for (int i = 0 ; i < m ; i++)
    cin >> girl[i];
    sort(boy,boy+n);
    sort(girl,girl+m);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (abs(boy[i] - girl[j]) <= 1){
                ans ++;
                girl[j] = MAXN*MAXN;
                break;
            }
        }
    }
    cout << ans << endl;
}
