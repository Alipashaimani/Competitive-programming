#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 2;
int dx[]{2,1,-1,-2,-2,-1,1,2};
int dy[]{1,2,2,1,-1,-2,-2,-1};
pair<int,int> q[MAXN*MAXN];
int table[MAXN][MAXN];
void bfs(int x, int y){
    table[x][y] = 0;
    int h = 0, t = 0;
    q[t++] = {x,y};
    
    while(t-h){
        x = q[h].first; y = q[h++].second;
        for ( int i = 0 ; i < 8 ; i++){
            if (x+dx[i]>= 0 && y+dy[i]>= 0 && x+dx[i] < 1001 && y+dy[i] < 1001 && table[x+dx[i]][y+dy[i]] == -1){
                table[x+dx[i]][y+dy[i]] = table[x][y]+1;
                q[t++] = {x+dx[i],y+dy[i]};
            }
        }
    }
}
int main(){
    memset(table,-1,sizeof(table));
    bfs(0,0);
    int t,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        printf("%d\n",table[x-1][y-1]);
    }
}
