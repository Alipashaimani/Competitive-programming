#include <bits/stdc++.h>
using namespace std ;

const long long  MAXN = 7e4 + 100 ;

bitset<MAXN> after, before, upd ;

int n, s, dp[MAXN], dp2[MAXN], par[MAXN] ;
pair<int,int> a[MAXN] ;
bool check[MAXN] ;

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> a[i].first ;
        dp[i] = a[i].first ;
        dp2[i] = -1 ;
        a[i].second = i ;
    }

    sort(a , a+n) ;

    before[0] = after[0] = true ;

    for(int i=0 ; i<n-1 ; i++){
        after = ((before << a[i].first) | before) ;
        upd = after ^ before ;
        while(upd.count() > 0 ){
            int j = upd._Find_first();
            par[j] = i ;
            upd[j] = false ;
        }
        before = after ;
    }

    if(s < a[n-1].first || !after[s-a[n-1].first])
        return cout << -1 << endl , 0 ;

    int ss = s-a[n-1].first ;
    check[n-1] = true ;
    while(ss > 0){
        int x = par[ss] ;
        ss -= a[x].first ;
        check[x] = true ;
    }


    int x = a[n-1].second;
    for(int i = n-1 ; i >= 0; i--){
        if(!check[i]){
        dp[x] -= a[i].first;
        dp2[x] = a[i].second;
        x = a[i].second;
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << dp[i] << " " ;
        if(dp2[i] == -1)
            cout << 0 ;
        else
            cout << 1 << " " << dp2[i]+1 ;
        cout << '\n';
    }
}