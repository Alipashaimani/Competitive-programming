// InTheNameOfGOD
// APIV
// Contest867
// PROB : C

#include<bits/stdc++.h>
#define show(x) cerr << #x << " " << x << endl;
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 100;


pair<pair<ll, ll>, pair<ll, ll> > piz[MAXN];
pair<ll , ll >  q[MAXN];

bool cmp(const pair<pair<ll, ll>, pair<ll, ll> > &x,const pair<pair<ll, ll>, pair<ll, ll> >  &y) {
    return x.second.second > y.second.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll k,sum = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> piz[i].first.first >> piz[i].first.second >> piz[i].second.first;
        piz[i].second.second = piz[i].first.second - piz[i].second.first;
        sum += piz[i].first.first;
    }
    sort(piz + 1, piz + 1 + n,cmp);

    sum = (sum + k - 1LL) / k;
    ll w1 = 0 ,w2 = 0, w3 = 0;
    for(int i = 1;i <= n;i++){
        if(piz[i].second.second>0)
            w1 += piz[i].first.first;
        else if(piz[i].second.second == 0)
            w2 += piz[i].first.first;
        else if(piz[i].second.second < 0)
            w3 += piz[i].first.first;
    }

    ll cnt1 =  (w1 + k - 1) / k;
    ll cnt2 = (w3 + k - 1) / k;
    ll ans = 0, cas = w1 + w2 + w3;

    //   show(cas);
    //   show(cnt1);
    //   show(cnt2);
    if(cnt1 + cnt2 <= sum)
        for(int i = 1;i <= n;i++)
            ans+=(piz[i].first.first*(max(piz[i].first.second,piz[i].second.first)));
    else {
        cnt1--;
        cnt2--;
        ll PP1 = cnt1 * k,PP3 = cnt2 * k;
        ll ans2 = 0, PP2 = cas - PP1 - PP3;
        // show(PP2);
        // show(PP1);

        bool flag = true;
        for(int i = 1; i <= n; i++) {
            if(PP1 >= 0 && flag) {
                if(piz[i].first.first <= PP1) {
                    PP1-=piz[i].first.first;
                    ans2+=piz[i].first.first*piz[i].first.second;
                }
                else {
                    piz[i].first.first -= PP1;
                    ans2 += PP1 * piz[i].first.second;
                    flag = false;
                    for(ll j = 0; j < PP2; j++) {
                        if(piz[i].first.first == 0) i++;
                        q[j].first = piz[i].first.second;
                        q[j].second = piz[i].second.first;
                        piz[i].first.first--;
                    }
                }
            }
        }
        //     show(PP1);
        //   show(ans2);
        for(int i = n; i > 0;i--) {
            if(PP3 > 0) {
                if(piz[i].first.first <= PP3) {
                    PP3 -= piz[i].first.first;
                    ans2 += piz[i].first.first * piz[i].second.first;
                }
                else {
                    ans2 += PP3 * piz[i].second.first;
                    PP3 = 0;
                }
            }
        }
        // show(ans2);

        ll t1 = 0,t2 = 0;
        for(ll i = 0; i < PP2 ;i++) {
            t1 += q[i].first;
            t2 += q[i].second;
        }
        // show(ans2);
        ans2 += max(t1,t2);
        ans = ans2;
    }
    cout << ans << '\n';
    return 0;
}