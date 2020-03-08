#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b[5000][2], cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt = 0;
    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        cin >> b[i][0];
        if ( b[i][0] == 1)
            cnt1 ++;
        else if (b[i][0] == 2)
            cnt2 ++;
        else
            cnt3 ++;

        b[i][1]= i;
    }
    bool flag = 0 ;
    cnt = min(cnt3, min(cnt1, cnt2));
    cout << cnt << '\n' ;
    for ( int i = 0 ; i < cnt ; i++){

        for ( int u = 1 ; u < 4 ; u++){
            flag = 0;
            for ( int j = 0 ; j < a ; j++){
                if ( b[j][0] == u){
                    b[j][0] = 10;
                    cout << (b[j][1])+1 << " ";
                    flag = 1;
                }
                if ( flag == 1)
                    break;
            }
        }
        cout << '\n';
    }
}