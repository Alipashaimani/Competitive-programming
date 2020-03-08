#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,ans1 = 0, ans2 = 0 , cnt = 1  ;
    cin >> a;
    vector<int>vec;

    for ( int i = 0 ; i < a ; i++ ){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort ( vec.begin(), vec.end());

    for ( int i = 0 ; i < a ; i++ ){

        if ( vec[i]!= vec[i-1]){
            ans2++;
            ans1 = max ( ans1 , cnt);
            cnt = 1 ;
        }

        else {
            cnt ++;
            ans1 = max ( ans1 , cnt);
        }
    }

    cout << ans1 <<" "<< ans2 ;
}