#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
int bot[MAXN][5];
int ans[5];
int n,m,k;
bool check(int x){
//    cout << x << endl;
    deque<pair<int, int > >q[5];
    for (int i = 0 ; i < n ; i++){
        int a = 0;
        for (int j = 0 ; j < m ; j++){
            if(q[j].size() && q[j].front().second <= i - x)
                q[j].pop_front();

            while(q[j].size() && q[j].back().first < bot[i][j])
                q[j].pop_back();
            q[j].push_back({bot[i][j],i});

            if (i >= x-1){
                a += q[j].front().first;
                ans[j] = q[j].front().first;
            }
        }
        if (i >= x - 1 && a <= k )
            return true;
    }
    return false;
}
int main(){
    cin >> n >> m >> k;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> bot[i][j];
        }
    }
    int b = 0,e = n;
    int mid = 0;
    while(b + 1 < e){
        mid = (b + e) >> 1 ;
        if (check(mid))
            b = mid;
        else
            e = mid;
    }
    if (check(b) == 0){
        for (int i = 0 ; i < m ; i++)
            cout << "0 ";
        return 0;
    }
    for (auto i = 0 ; i < m ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}