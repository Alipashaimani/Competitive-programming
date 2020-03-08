#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e16;
vector<int>vec;
set<int>st;
int ans = 1e18;
void pdiv(int num){
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0){
            st.insert(i);
            while(num % i == 0)
                num /= i;
        }
    if (num>1)
        st.insert(num);
}

int32_t main(){
    int a, b, n;  cin >> n >> a >> b;
    for (int i = 0; i < n; i++){
        int x;  cin >> x;
        vec.push_back(x);
    }
    pdiv(vec[0]); pdiv(vec[0]+1); pdiv(vec[0]-1);
    pdiv(vec[vec.size()-1]); pdiv(vec[vec.size()-1]-1); pdiv(vec[vec.size()-1]+1);

    for (auto p : st){
        int dp1 = 0, dp2 = 0, dp3 = 0, cur = MAXN;
        for (int i = 0 ; i < n ; i++){
            cur = MAXN ;

            if(vec[i] % p == 0)
                cur = 0;

            else if((vec[i] + 1) % p == 0 or (vec[i] - 1) % p == 0)
                cur = b;

            dp1 += cur;
            dp2 += a;
            dp3 += cur;

            dp1 = min((int)MAXN , dp1);
            dp2 = min(dp1,dp2);
            dp3 = min(dp3,dp2);
        }
        ans = min(ans,dp3);
    }
    cout << ans << endl;
}
