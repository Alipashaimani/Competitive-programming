#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
pair<int , int >pii[MAXN];
long long cur = 0;
long long ans = 0;
int j = 0 ;
int a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    for (int i = 0 ; i < a ; i++)
        cin >> pii[i].first >> pii[i].second;

    sort(pii,pii+a);

    for (int i = 0 ; i < a ; i++){
        while(j < a && pii[j].first - pii[i].first < b)
            cur += pii[j++].second;

        ans = max(ans,cur);
        cur -= pii[i].second;
    }
    return cout << ans << '\n' , 0;
}