#include<bits/stdc++.h>
using namespace std;

const int MAXN = 310;
const int INF = 1e9;
bool mark[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN],a[MAXN][MAXN],n,cnt;

int memo(const int &x1, const int &y1, const int &x2){
    if(x1<0||x1>=n||y1<0||y1>=n||x2<0||x2>=n)
        return -(INF);

    if(x1==n-1 && y1==n-1 && x2==n-1)
        return a[x1][y1];

    if(!mark[x1][y1][x2]){
        mark[x1][y1][x2] = true;
        int &cur = dp[x1][y1][x2];
        int y2 = x1 + y1 - x2;

        if(x1==x2 && y1==y2)
            cur=a[x1][y1];
        else
            cur = a[x1][y1] + a[x2][y2];
        cur += max(max(memo(x1+1, y1, x2+1), memo(x1+1, y1, x2)) , max(memo(x1, y1+1, x2+1), memo(x1, y1+1, x2)));
    }
    return dp[x1][y1][x2];
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    cout << memo(0, 0, 0) << endl;
}
