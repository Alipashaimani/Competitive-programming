#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0, from;
int main(){

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x >= 8){
            from += (x - 8);
            cnt += 8;
            x = 8;
        }
        else {
            if(from >= 8){
                from = from - 8 + x;
                cnt += 8;
            }
            else if(from + x >= 8){
                from = from + x - 8;
                cnt += 8;
            }
            else{
                cnt += (from + x);
                from = 0;
            }
        }
        if(cnt >= k)
            return cout << i + 1, 0;
    }
    return cout << -1, 0;
}