#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

int a[MAXN];
bool flag = false;

int main(){
    int n;  cin >> n;
    for(int i = 1; i <=n; i++)
        cin >> a[i];

    for(int i = 30; i>=0; i--){
        flag = false;
        int res = 0, cnt = 0;
        for(int j = 1; j <= n; j++)
            if(a[j] & (1 << i)){
                if(!flag){
                    res = a[j];
                    flag = true;
                }
                else{
                    res &= a[j];
                }
                cnt++;
            }
        if(flag && ((res&(-res)) == (1<<i))){
            cout << cnt << '\n';
            for(int j = 1; j <=n; j++)
                if(a[j] & (1<<i))
                    cout << a[j] << " ";
            return 0;
        }
    }
    return 0;
}