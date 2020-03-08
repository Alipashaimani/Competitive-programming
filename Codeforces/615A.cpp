#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, cnt = 0, ans = 1 ;
    vector<int>vec;
    cin >> a >> b;
    for ( int i = 0 ; i < a ; i++ ){
        int x;
        cin >> x;
        for ( int j = 0 ; j < x ; j++){
            int y;
            cin >> y ;
            vec.push_back(y);
            cnt ++;
        }
    }
    sort (vec.begin(), vec.end());

    for ( int i = 0 ;i < cnt ; i++ ){

        if ( vec[i] == ans)
            ans ++ ;

        if ( (ans - 1) == b){
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";

}
