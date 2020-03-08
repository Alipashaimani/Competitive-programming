#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e4, maxp = 202;
short int dp[maxn][maxp];
int pn[maxp], n;

bool isprime(int n){
    if(n <= 1)
        return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int DP(int i, int j)
{
    if(i >= 0 && j >= 0)
        return dp[i][j];
    return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    mset(dp, -1);
    int c = 1, j = 0;
    cin >> n;

    reu(i, 2, n){
        if(isprime(i)){
            if(isprime(c)){
                rep(k, n){
                    if(k - i == -1)
                        dp[j][k] = 1;
                    else if(k - i < -1 || DP(j, k - i) == -1){
                        if(j != 0)
                            dp[j][k] = DP(j - 1, k);
                    }
                    else if(j == 0 || DP(j - 1, k) == -1){
                        dp[j][k] = DP(j, k - i) + 1;
                    }
                    else
                        dp[j][k] = min(DP(j, k - i) + 1, DP(j - 1, k));
                }
                pn[j] = i;
                j ++;
            }
            c ++;
        }
    }
    if(j < 1 || DP(j - 1, n - 1) == -1){
        cout << 0 << endl;
        return 0;
    }
    cout << DP(j - 1, n - 1) << endl;
    int p = j - 1;
    int q = n - 1;
    while(q >= 0 && p >= 0){
        if(q - pn[p] == -1){
            cout << pn[p] << ' ';
            q -= pn[p];
        }
        else if(q - pn[p] >= 0 && DP(p, q) == DP(p, q - pn[p]) + 1){
            cout << pn[p] << ' ';
            q -= pn[p];
        }
        else
            p --;
    }
    cout << endl;
	return 0;
}
