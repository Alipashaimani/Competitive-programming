#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 1e5 + 100;

int shops[MAXN], days[MAXN];
int main (){
    int n ; cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> shops[i] ;
    sort (shops, shops + n ) ;

    int q ; cin >> q ;
    for (int i = 0 ; i < q ; i++)
        cin >> days[i] ;

    for (int i = 0 ; i < q ; i++)
        cout << upper_bound(shops, shops + n, days[i]) - shops << endl ;
}