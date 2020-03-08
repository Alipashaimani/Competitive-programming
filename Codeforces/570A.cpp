#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 1e5;
int n , m ;
int vote[MAXN], win[MAXN];
int indexM;
int main () {
    cin >> n >> m ;
    for (int i = 0 ; i < m ; ++i){
        indexM = 0 ;
        for (int j = 0 ; j < n ; ++j){
            cin >> vote[j] ;
            if (vote[j] > vote[indexM])
                indexM = j ;
        }
        ++win[indexM + 1];
    }
    indexM = 1 ;
    for (int i = 1 ; i <= n ; ++i){
        if (win[i] > win[indexM])
            indexM = i ;
    }
    cout << indexM ;
}