#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
int main(){
    cin >> n;
    while(n--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ans += ((x2-x1+1)*(y2-y1+1));
    }
    cout << ans << endl;
}
