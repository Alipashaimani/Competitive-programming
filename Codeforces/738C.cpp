#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+100;
pair<int,int> car[MAXN];
int station[MAXN];
int n, k, s, t;

bool check(long long mid){
    int TimeSum = 0 ;
    for (int i = 1 ; i <= k+1 ; i++){
        long long delta = station[i] - station[i-1];
        if ( delta > mid)
            return false;
        TimeSum += (2*delta)-min(delta, mid-delta);
    }
    return TimeSum <= t;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s >> t;

    for ( int i = 0 ; i < n ; i++)
        cin >> car[i].first >> car[i].second;

    for ( int i = 1 ; i <= k ; i++)
        cin >> station[i];

    station[k+1] = s;
    sort(station , station+k+1);

    long long l = 0 ,r = 2*s;
    int minMoney = -1;
    if ( t >= s){
    while(l+1<r){
        long long mid = (l+r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    for (int i = 0 ; i < n ; i++)
        if ( car[i].second >= r && (minMoney == -1 || minMoney > car[i].first))
            minMoney = car[i].first;
    }
    cout << minMoney << '\n';
    return 0;
}
