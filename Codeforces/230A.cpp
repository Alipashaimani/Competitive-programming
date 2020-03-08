#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a, b;
    pair <long long, long long> x[10000];
    cin >> b >> a;
    for ( int i = 0 ; i < a ; i++){
        cin >> x[i].first >> x[i].second;
    }
    sort(x,x+a);

    for ( int i = 0 ; i < a ; i++){
        if ( x[i].first < b){
            b += x[i].second;
        }
        else{
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

}